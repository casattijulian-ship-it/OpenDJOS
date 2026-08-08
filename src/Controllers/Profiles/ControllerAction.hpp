#pragma once

#include "../Types/Button.hpp"
#include "../Types/ButtonState.hpp"
#include "../Types/Deck.hpp"
#include "../Types/Fader.hpp"
#include "../Types/Knob.hpp"
#include "../Types/Encoder.hpp"
#include "../Types/JogWheel.hpp"
#include "../Types/JogTouchState.hpp"
#include "../Types/PerformancePad.hpp"
#include "../Types/PadMode.hpp"

#include <cstdint>

namespace OpenDJ
{

enum class ControllerActionType
{
    None,

    Button,
    Fader,
    Knob,
    Encoder,
    JogWheel,
    JogTouch,

    PerformancePad
};

struct ControllerAction
{
    ControllerActionType type = ControllerActionType::None;

    Deck deck = Deck::None;

    Button button = Button::Unknown;

    Fader fader = Fader::Channel;

    Knob knob = Knob::Trim;

    // Mantener estos dos campos aquí para conservar
    // compatibilidad con los perfiles existentes.
    ButtonState buttonState = ButtonState::Released;

    std::uint16_t value = 0;

    // Nuevos tipos añadidos al final.
    Encoder encoder = Encoder::Browse;

    JogWheel jogWheel = JogWheel::Platter;

    JogTouchState jogTouchState = JogTouchState::Released;

    PerformancePad performancePad = PerformancePad::Pad1;

    PadMode padMode = PadMode::HotCue;
};

} // namespace OpenDJ