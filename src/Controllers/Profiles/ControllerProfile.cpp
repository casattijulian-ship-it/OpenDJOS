#include "ControllerProfile.hpp"

namespace OpenDJ
{

void ControllerProfile::addEntry(const ProfileEntry& entry)
{
    m_entries.push_back(entry);
}

std::optional<ProfileEntry> ControllerProfile::find(
    const MidiEvent& event) const
{
    return find(
        event.type,
        event.channel,
        event.number);
}

std::optional<ProfileEntry> ControllerProfile::find(
    MidiMessageType messageType,
    std::uint8_t channel,
    std::uint8_t number) const
{
    for (const auto& entry : m_entries)
    {
        if (entry.messageType == messageType &&
            entry.channel == channel &&
            entry.number == number)
        {
            return entry;
        }
    }

    return std::nullopt;
}

} // namespace OpenDJ