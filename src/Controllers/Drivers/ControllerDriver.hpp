#pragma once

#include "../MIDI/MidiEvent.hpp"

namespace OpenDJ
{

class ControllerDriver
{
public:

    virtual ~ControllerDriver() = default;

    virtual bool open() = 0;

    virtual void close() = 0;

    virtual bool poll(MidiEvent& event) = 0;
};

}