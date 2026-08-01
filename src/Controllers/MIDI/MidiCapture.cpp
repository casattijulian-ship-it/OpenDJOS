#include "MidiCapture.hpp"

#include "Core/Logging/Logger.hpp"

#include <string>

namespace OpenDJ
{

std::uint32_t MidiCapture::makeKey(
    MidiMessageType type,
    std::uint8_t channel,
    std::uint8_t number)
{
    return
        (static_cast<std::uint32_t>(type) << 16) |
        (static_cast<std::uint32_t>(channel) << 8) |
        static_cast<std::uint32_t>(number);
}

void MidiCapture::process(const MidiEvent& event)
{
    // ============================================================
    // DETECTAR CONTROL MIDI NUEVO
    // ============================================================

    const auto key =
        makeKey(
            event.type,
            event.channel,
            event.number);

    if (m_seenControls.insert(key).second)
    {
        Logger::info(
            "[CAPTURE] NEW MIDI CONTROL -> type=" +
            std::to_string(static_cast<int>(event.type)) +
            " channel=" +
            std::to_string(static_cast<int>(event.channel)) +
            " number=" +
            std::to_string(static_cast<int>(event.number)));
    }

    // ============================================================
    // DETECTAR CONTROL 14-BIT
    // ============================================================

    auto event14Bit =
        m_14BitProcessor.process(event);

    if (event14Bit)
    {
        Logger::info(
            "[CAPTURE] 14-BIT -> channel=" +
            std::to_string(
                static_cast<int>(event14Bit->channel)) +
            " MSB=" +
            std::to_string(
                static_cast<int>(event14Bit->number)) +
            " LSB=" +
            std::to_string(
                static_cast<int>(event14Bit->number + 32)) +
            " value=" +
            std::to_string(event14Bit->value));
    }
}

void MidiCapture::reset()
{
    m_seenControls.clear();

    m_14BitProcessor =
        Midi14BitProcessor{};
}

} // namespace OpenDJ