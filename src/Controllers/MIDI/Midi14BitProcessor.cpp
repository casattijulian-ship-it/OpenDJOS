#include "Midi14BitProcessor.hpp"

namespace OpenDJ
{

std::optional<Midi14BitEvent> Midi14BitProcessor::process(
    const MidiEvent& event)
{
    // Solo procesamos mensajes Control Change.
    if (event.type != MidiMessageType::ControlChange)
    {
        return std::nullopt;
    }

    // MIDI 14-bit utiliza:
    //
    // MSB -> CC 0 - 31
    // LSB -> CC 32 - 63
    //
    // Ejemplo DDJ-400:
    //
    // Channel Fader:
    // MSB = CC 19
    // LSB = CC 51
    //
    // 51 - 32 = 19

    std::uint8_t baseNumber = 0;

    bool isMsb = false;
    bool isLsb = false;

    if (event.number <= 31)
    {
        baseNumber = event.number;
        isMsb = true;
    }
    else if (event.number >= 32 &&
             event.number <= 63)
    {
        baseNumber =
            static_cast<std::uint8_t>(
                event.number - 32);

        isLsb = true;
    }
    else
    {
        return std::nullopt;
    }

    const auto key =
        makeKey(
            event.channel,
            baseNumber);

    auto& state = m_states[key];

    if (isMsb)
    {
        state.msb = event.value;
        state.hasMsb = true;
    }

    if (isLsb)
    {
        state.lsb = event.value;
        state.hasLsb = true;
    }

    // Esperamos hasta tener ambas partes.
    if (!state.hasMsb || !state.hasLsb)
    {
        return std::nullopt;
    }

    // MIDI 14-bit:
    //
    // MSB ocupa los 7 bits superiores.
    // LSB ocupa los 7 bits inferiores.
    //
    // value = (MSB << 7) | LSB

    const std::uint16_t value =
        static_cast<std::uint16_t>(
            (static_cast<std::uint16_t>(state.msb) << 7) |
            static_cast<std::uint16_t>(state.lsb));

    Midi14BitEvent result;

    result.channel = event.channel;
    result.number = baseNumber;
    result.value = value;

    // Reiniciamos el par para esperar
    // el siguiente valor completo.
    state.hasMsb = false;
    state.hasLsb = false;

    return result;
}

std::uint16_t Midi14BitProcessor::makeKey(
    std::uint8_t channel,
    std::uint8_t number)
{
    return static_cast<std::uint16_t>(
        (static_cast<std::uint16_t>(channel) << 8) |
        static_cast<std::uint16_t>(number));
}

} // namespace OpenDJ