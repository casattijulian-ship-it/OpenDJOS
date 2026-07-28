#pragma once

#include "ControllerAction.hpp"
#include "../MIDI/MidiTypes.hpp"

#include <cstdint>

namespace OpenDJ
{

struct ProfileEntry
{
    MidiMessageType messageType = MidiMessageType::Unknown;

    std::uint8_t channel = 0;

    std::uint8_t number = 0;

    ControllerAction action;
};

} // namespace OpenDJ