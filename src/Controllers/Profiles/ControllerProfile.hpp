#pragma once

#include "ProfileEntry.hpp"
#include "../MIDI/MidiEvent.hpp"

#include <cstdint>
#include <optional>
#include <vector>

namespace OpenDJ
{

class ControllerProfile
{
public:

    void addEntry(const ProfileEntry& entry);

    std::optional<ProfileEntry> find(
        const MidiEvent& event) const;

    std::optional<ProfileEntry> find(
        MidiMessageType messageType,
        std::uint8_t channel,
        std::uint8_t number) const;

private:

    std::vector<ProfileEntry> m_entries;
};

} // namespace OpenDJ