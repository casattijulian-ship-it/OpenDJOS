#include "ControllerMapper.hpp"

#include "ButtonEvent.hpp"
#include "FaderEvent.hpp"
#include "KnobEvent.hpp"
#include "EncoderEvent.hpp"
#include "JogWheelEvent.hpp"
#include "JogTouchEvent.hpp"

#include <cstdint>

namespace OpenDJ
{

namespace
{

// ============================================================
// RELATIVE MIDI VALUE -> SIGNED DELTA
// Usado por encoders como BROWSE.
// ============================================================

std::int16_t relativeMidiToDelta(std::uint8_t value)
{
    if (value == 64)
    {
        return 0;
    }

    if (value < 64)
    {
        return static_cast<std::int16_t>(value);
    }

    return static_cast<std::int16_t>(value) - 128;
}

// ============================================================
// DDJ-400 JOG MIDI VALUE -> SIGNED DELTA
//
// 63 -> +1
// 62 -> +2
// 61 -> +3
// 64 ->  0
// 65 -> -1
// 66 -> -2
// 67 -> -3
// ============================================================

std::int16_t jogMidiToDelta(std::uint8_t value)
{
    return static_cast<std::int16_t>(64) -
           static_cast<std::int16_t>(value);
}

} // namespace

ControllerMapper::ControllerMapper(
    const ControllerProfile& profile)
    : m_profile(profile)
{
}

// ============================================================
// MIDI 7-BIT
// ============================================================

std::unique_ptr<ControllerEvent> ControllerMapper::map(
    const MidiEvent& event) const
{
    auto entry = m_profile.find(event);

    if (!entry)
    {
        return nullptr;
    }

    switch (entry->action.type)
    {
        // ====================================================
        // BUTTON
        // ====================================================

        case ControllerActionType::Button:
        {
            // El estado real del botón se obtiene
            // directamente del valor MIDI recibido.
            //
            // value > 0 -> PRESSED
            // value = 0 -> RELEASED

            const auto state =
                event.value > 0
                    ? ButtonState::Pressed
                    : ButtonState::Released;

            return std::make_unique<ButtonEvent>(
                entry->action.deck,
                entry->action.button,
                state);
        }

        // ====================================================
        // FADER
        // ====================================================

        case ControllerActionType::Fader:
        {
            return std::make_unique<FaderEvent>(
                entry->action.deck,
                entry->action.fader,
                entry->action.value);
        }

        // ====================================================
        // KNOB
        // ====================================================

        case ControllerActionType::Knob:
        {
            return std::make_unique<KnobEvent>(
                entry->action.deck,
                entry->action.knob,
                entry->action.value);
        }

        // ====================================================
        // ENCODER
        // ====================================================

        case ControllerActionType::Encoder:
        {
            const auto delta =
                relativeMidiToDelta(event.value);

            return std::make_unique<EncoderEvent>(
                entry->action.encoder,
                delta);
        }

        // ====================================================
        // JOG WHEEL
        // ====================================================

        case ControllerActionType::JogWheel:
        {
            const auto delta =
                jogMidiToDelta(event.value);

            if (delta == 0)
            {
                return nullptr;
            }

            return std::make_unique<JogWheelEvent>(
                entry->action.deck,
                entry->action.jogWheel,
                delta);
        }

        // ====================================================
        // JOG TOUCH
        // ====================================================

        case ControllerActionType::JogTouch:
        {
            // DDJ-400:
            // value 127 -> superficie tocada
            // value   0 -> superficie liberada

            const auto state =
                event.value > 0
                    ? JogTouchState::Touched
                    : JogTouchState::Released;

            return std::make_unique<JogTouchEvent>(
                entry->action.deck,
                state);
        }

        default:
        {
            return nullptr;
        }
    }
}

// ============================================================
// MIDI 14-BIT
// ============================================================

std::unique_ptr<ControllerEvent> ControllerMapper::map(
    const Midi14BitEvent& event) const
{
    auto entry = m_profile.find(
        MidiMessageType::ControlChange,
        event.channel,
        event.number);

    if (!entry)
    {
        return nullptr;
    }

    switch (entry->action.type)
    {
        // ====================================================
        // FADER
        // ====================================================

        case ControllerActionType::Fader:
        {
            return std::make_unique<FaderEvent>(
                entry->action.deck,
                entry->action.fader,
                event.value);
        }

        // ====================================================
        // KNOB
        // ====================================================

        case ControllerActionType::Knob:
        {
            return std::make_unique<KnobEvent>(
                entry->action.deck,
                entry->action.knob,
                event.value);
        }

        default:
        {
            return nullptr;
        }
    }
}

} // namespace OpenDJ