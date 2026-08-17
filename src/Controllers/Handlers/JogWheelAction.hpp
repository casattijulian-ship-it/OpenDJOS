#pragma once

#include "../Types/Deck.hpp"
#include "../Types/JogWheel.hpp"

#include <cstdint>

namespace OpenDJ
{

enum class JogWheelActionType
{
    None,

    Platter,
    Scratch,
    Search
};

struct JogWheelAction
{
    JogWheelActionType type =
        JogWheelActionType::None;

    Deck deck =
        Deck::None;

    JogWheel jogWheel =
        JogWheel::Platter;

    std::int16_t delta =
        0;
};

} // namespace OpenDJ
