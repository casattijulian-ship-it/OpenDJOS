#pragma once

#include "ControllerEvent.hpp"

#include "../Types/Button.hpp"
#include "../Types/ButtonState.hpp"
#include "../Types/Deck.hpp"

#include "Core/Events/EventType.hpp"

#include <string_view>

namespace OpenDJ
{

class ButtonEvent final : public ControllerEvent
{
public:

    ButtonEvent(
        Deck deck,
        Button button,
        ButtonState state);

    EventType type() const override;

    std::string_view name() const override;

    Deck deck() const;

    Button button() const;

    ButtonState state() const;

private:

    Deck m_deck;
    Button m_button;
    ButtonState m_state;
};

} // namespace OpenDJ