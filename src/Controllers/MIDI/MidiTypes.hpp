#pragma once

#include <cstdint>

namespace OpenDJ
{

enum class MidiMessageType : uint8_t
{
    Unknown = 0,

    NoteOn,
    NoteOff,

    ControlChange,

    PitchBend,

    ProgramChange,

    ChannelPressure,

    PolyphonicPressure,

    SystemExclusive
};

}