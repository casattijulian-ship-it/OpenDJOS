#pragma once

#include "ControllerEvent.hpp"

#include "../Types/ButtonState.hpp"
#include "../Types/Deck.hpp"
#include "../Types/PadMode.hpp"
#include "../Types/PerformancePad.hpp"

#include <string_view>

namespace OpenDJ
{

class PerformancePadEvent final : public ControllerEvent
{
public:

    PerformancePadEvent(
        Deck deck,
        PerformancePad performancePad,
        PadMode padMode,
        ButtonState state);

    EventType type() const override;

    std::string_view name() const override;

    Deck deck() const;

    PerformancePad performancePad() const;

    PadMode padMode() const;

    ButtonState state() const;

private:

    Deck m_deck;

    PerformancePad m_performancePad;

    PadMode m_padMode;

    ButtonState m_state;
};

} // namespace OpenDJ
