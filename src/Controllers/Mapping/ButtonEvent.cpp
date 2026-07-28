#include "ButtonEvent.hpp"

namespace OpenDJ
{

ButtonEvent::ButtonEvent(
    Deck deck,
    Button button,
    ButtonState state)
    : m_deck(deck),
      m_button(button),
      m_state(state)
{
}

EventType ButtonEvent::type() const
{
    return EventType::Button;
}

std::string_view ButtonEvent::name() const
{
    return "ButtonEvent";
}

Deck ButtonEvent::deck() const
{
    return m_deck;
}

Button ButtonEvent::button() const
{
    return m_button;
}

ButtonState ButtonEvent::state() const
{
    return m_state;
}

} // namespace OpenDJ