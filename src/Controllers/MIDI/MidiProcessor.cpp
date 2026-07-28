#include "MidiProcessor.hpp"

namespace OpenDJ
{

MidiProcessor::MidiProcessor(const ControllerProfile& profile)
    : m_mapper(profile)
{
}

std::unique_ptr<ControllerEvent> MidiProcessor::process(
    const MidiEvent& event) const
{
    return m_mapper.map(event);
}

} // namespace OpenDJ