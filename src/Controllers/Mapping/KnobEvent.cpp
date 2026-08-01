#include "KnobEvent.hpp"

namespace OpenDJ
{

KnobEvent::KnobEvent(
    Deck deck,
    Knob knob,
    std::uint16_t value)
    : m_deck(deck),
      m_knob(knob),
      m_value(value)
{
}

EventType KnobEvent::type() const
{
    return EventType::Knob;
}

std::string_view KnobEvent::name() const
{
    return "KnobEvent";
}

Deck KnobEvent::deck() const
{
    return m_deck;
}

Knob KnobEvent::knob() const
{
    return m_knob;
}

std::uint16_t KnobEvent::value() const
{
    return m_value;
}

} // namespace OpenDJ