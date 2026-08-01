#pragma once

#include "ControllerEvent.hpp"

#include "../Types/Deck.hpp"
#include "../Types/JogTouchState.hpp"

#include <string_view>

namespace OpenDJ
{

class JogTouchEvent final : public ControllerEvent
{
public:

    JogTouchEvent(
        Deck deck,
        JogTouchState state);

    EventType type() const override;

    std::string_view name() const override;

    Deck deck() const;

    JogTouchState state() const;

private:

    Deck m_deck;

    JogTouchState m_state;
};

} // namespace OpenDJ