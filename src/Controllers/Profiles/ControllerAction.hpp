#pragma once

#include "../Types/Button.hpp"
#include "../Types/ButtonState.hpp"
#include "../Types/Deck.hpp"
#include "../Types/Fader.hpp"

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
    JogWheel
};

struct ControllerAction
{
    ControllerActionType type = ControllerActionType::None;

    Deck deck = Deck::None;

    Button button = Button::Unknown;

    Fader fader = Fader::Channel;

    ButtonState buttonState = ButtonState::Released;

    std::uint16_t value = 0;
};

} // namespace OpenDJ