#pragma once

#include "ControllerEvent.hpp"

#include "../MIDI/MidiEvent.hpp"
#include "../MIDI/Midi14BitProcessor.hpp"
#include "../Profiles/ControllerProfile.hpp"

#include <memory>

namespace OpenDJ
{

class ControllerMapper
{
public:

    ControllerMapper(const ControllerProfile& profile);

    std::unique_ptr<ControllerEvent> map(
        const MidiEvent& event) const;

    std::unique_ptr<ControllerEvent> map(
        const Midi14BitEvent& event) const;

private:

    const ControllerProfile& m_profile;
};

} // namespace OpenDJ