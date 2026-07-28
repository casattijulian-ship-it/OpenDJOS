#include "FaderEvent.hpp"

namespace OpenDJ
{

FaderEvent::FaderEvent(
    Deck deck,
    Fader fader,
    std::uint16_t value)
    : m_deck(deck),
      m_fader(fader),
      m_value(value)
{
}
EventType FaderEvent::type() const
{
    return EventType::Fader;
}

std::string_view FaderEvent::name() const
{
    return "FaderEvent";
}

Deck FaderEvent::deck() const
{
    return m_deck;
}

Fader FaderEvent::fader() const
{
    return m_fader;
}

std::uint16_t FaderEvent::value() const
{
    return m_value;
}

} // namespace OpenDJ