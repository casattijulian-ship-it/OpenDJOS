#pragma once

#include "ProfileEntry.hpp"
#include "../MIDI/MidiEvent.hpp"

#include <optional>
#include <vector>

namespace OpenDJ
{

class ControllerProfile
{
public:

    void addEntry(const ProfileEntry& entry);

    std::optional<ProfileEntry> find(const MidiEvent& event) const;

private:

    std::vector<ProfileEntry> m_entries;
};

} // namespace OpenDJ