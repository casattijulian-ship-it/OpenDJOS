#include "PerformancePadEvent.hpp"

namespace OpenDJ
{

PerformancePadEvent::PerformancePadEvent(
    Deck deck,
    PerformancePad performancePad,
    PadMode padMode,
    ButtonState state)
    : m_deck(deck),
      m_performancePad(performancePad),
      m_padMode(padMode),
      m_state(state)
{
}

EventType PerformancePadEvent::type() const
{
    return EventType::PerformancePad;
}

std::string_view PerformancePadEvent::name() const
{
    return "PerformancePadEvent";
}

Deck PerformancePadEvent::deck() const
{
    return m_deck;
}

PerformancePad PerformancePadEvent::performancePad() const
{
    return m_performancePad;
}

PadMode PerformancePadEvent::padMode() const
{
    return m_padMode;
}

ButtonState PerformancePadEvent::state() const
{
    return m_state;
}

} // namespace OpenDJ
