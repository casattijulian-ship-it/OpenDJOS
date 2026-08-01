#include "JogTouchEvent.hpp"

namespace OpenDJ
{

JogTouchEvent::JogTouchEvent(
    Deck deck,
    JogTouchState state)
    : m_deck(deck),
      m_state(state)
{
}

EventType JogTouchEvent::type() const
{
    return EventType::JogTouch;
}

std::string_view JogTouchEvent::name() const
{
    return "JogTouchEvent";
}

Deck JogTouchEvent::deck() const
{
    return m_deck;
}

JogTouchState JogTouchEvent::state() const
{
    return m_state;
}

} // namespace OpenDJ