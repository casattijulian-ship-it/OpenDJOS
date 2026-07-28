#include "ControllerProfile.hpp"

namespace OpenDJ
{

void ControllerProfile::addEntry(const ProfileEntry& entry)
{
    m_entries.push_back(entry);
}

std::optional<ProfileEntry> ControllerProfile::find(const MidiEvent& event) const
{
    for (const auto& entry : m_entries)
    {
        if (entry.messageType == event.type &&
            entry.channel == event.channel &&
            entry.number == event.number)
        {
            return entry;
        }
    }

    return std::nullopt;
}

} // namespace OpenDJ