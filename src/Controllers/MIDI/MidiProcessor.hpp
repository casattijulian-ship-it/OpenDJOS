#pragma once

#include "../Mapping/ControllerMapper.hpp"
#include "../Profiles/ControllerProfile.hpp"

#include "MidiEvent.hpp"
#include "Midi14BitProcessor.hpp"

#include <memory>

namespace OpenDJ
{

class ControllerEvent;

class MidiProcessor
{
public:

    explicit MidiProcessor(const ControllerProfile& profile);

    std::unique_ptr<ControllerEvent> process(
        const MidiEvent& event) const;

    std::unique_ptr<ControllerEvent> process(
        const Midi14BitEvent& event) const;

private:

    ControllerMapper m_mapper;
};

} // namespace OpenDJ