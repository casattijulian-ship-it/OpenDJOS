#pragma once

#include "MidiEvent.hpp"

namespace OpenDJ
{

class MidiInput
{
public:

    MidiInput();

    ~MidiInput();

    bool open();

    void close();

    bool poll(MidiEvent& event);
};

}