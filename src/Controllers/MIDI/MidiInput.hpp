#pragma once

#include "MidiDevice.hpp"
#include "MidiEvent.hpp"

#include <alsa/asoundlib.h>

namespace OpenDJ
{

class MidiInput
{
public:

    explicit MidiInput(const MidiDevice& device);

    ~MidiInput();

    MidiInput(const MidiInput&) = delete;
    MidiInput& operator=(const MidiInput&) = delete;

    MidiInput(MidiInput&&) = delete;
    MidiInput& operator=(MidiInput&&) = delete;

    bool open();

    void close();

    bool poll(MidiEvent& event);

    bool isOpen() const;

private:

    const MidiDevice& m_device;

    snd_seq_t* m_sequencer = nullptr;

    int m_port = -1;
};

} // namespace OpenDJ