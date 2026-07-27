#pragma once

#include <cstdint>
#include "MidiTypes.hpp"

namespace OpenDJ
{

struct MidiEvent
{
    MidiMessageType type;

    uint8_t channel;

    uint8_t number;

    uint8_t value;
};

}