#pragma once

#include "ControllerEvent.hpp"

#include "../Types/Encoder.hpp"

#include <cstdint>
#include <string_view>

namespace OpenDJ
{

class EncoderEvent final : public ControllerEvent
{
public:

    EncoderEvent(
        Encoder encoder,
        std::int16_t delta);

    EventType type() const override;

    std::string_view name() const override;

    Encoder encoder() const;

    std::int16_t delta() const;

private:

    Encoder m_encoder;

    std::int16_t m_delta;
};

} // namespace OpenDJ