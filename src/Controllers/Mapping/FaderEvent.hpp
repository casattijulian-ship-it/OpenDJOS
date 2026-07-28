#pragma once

#include "ControllerEvent.hpp"

#include "../Types/Deck.hpp"
#include "../Types/Fader.hpp"

#include "Core/Events/EventType.hpp"

#include <cstdint>
#include <string_view>

namespace OpenDJ
{

class FaderEvent final : public ControllerEvent
{
public:

    FaderEvent(
        Deck deck,
        Fader fader,
        std::uint16_t value);

    EventType type() const override;

    std::string_view name() const override;

    Deck deck() const;

    Fader fader() const;

    std::uint16_t value() const;

private:

    Deck m_deck;

    Fader m_fader;

    std::uint16_t m_value;
};

} // namespace OpenDJ