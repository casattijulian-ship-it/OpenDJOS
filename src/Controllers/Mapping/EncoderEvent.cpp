#include "EncoderEvent.hpp"

namespace OpenDJ
{

EncoderEvent::EncoderEvent(
    Encoder encoder,
    std::int16_t delta)
    : m_encoder(encoder),
      m_delta(delta)
{
}

EventType EncoderEvent::type() const
{
    return EventType::Encoder;
}

std::string_view EncoderEvent::name() const
{
    return "EncoderEvent";
}

Encoder EncoderEvent::encoder() const
{
    return m_encoder;
}

std::int16_t EncoderEvent::delta() const
{
    return m_delta;
}

} // namespace OpenDJ