#pragma once

#include "MidiDevice.hpp"

#include <alsa/asoundlib.h>

#include <optional>
#include <string>
#include <vector>

namespace OpenDJ
{

class MidiDeviceManager
{
public:

    MidiDeviceManager();

    ~MidiDeviceManager();

    MidiDeviceManager(const MidiDeviceManager&) = delete;
    MidiDeviceManager& operator=(const MidiDeviceManager&) = delete;

    MidiDeviceManager(MidiDeviceManager&&) = delete;
    MidiDeviceManager& operator=(MidiDeviceManager&&) = delete;

    std::vector<MidiDevice> enumerate() const;

    std::optional<MidiDevice> findByName(const std::string& name) const;

private:

    snd_seq_t* m_sequencer = nullptr;
};

} // namespace OpenDJ