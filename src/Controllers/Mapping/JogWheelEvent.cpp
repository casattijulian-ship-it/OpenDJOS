#include "JogWheelEvent.hpp"

namespace OpenDJ
{

JogWheelEvent::JogWheelEvent(
    Deck deck,
    JogWheel jogWheel,
    std::int16_t delta)
    : m_deck(deck),
      m_jogWheel(jogWheel),
      m_delta(delta)
{
}

EventType JogWheelEvent::type() const
{
    return EventType::JogWheel;
}

std::string_view JogWheelEvent::name() const
{
    return "JogWheelEvent";
}

Deck JogWheelEvent::deck() const
{
    return m_deck;
}

JogWheel JogWheelEvent::jogWheel() const
{
    return m_jogWheel;
}

std::int16_t JogWheelEvent::delta() const
{
    return m_delta;
}

} // namespace OpenDJ