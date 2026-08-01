#pragma once

#include "IService.hpp"

#include "Controllers/MIDI/Midi14BitProcessor.hpp"
#include "Controllers/MIDI/MidiDeviceManager.hpp"
#include "Controllers/MIDI/MidiInput.hpp"
#include "Controllers/MIDI/MidiProcessor.hpp"
#include "Controllers/MIDI/MidiCapture.hpp"

#include "Controllers/Profiles/ControllerProfile.hpp"

#include <memory>

namespace OpenDJ
{

class MidiService final : public IService
{
public:

    MidiService() = default;

    ~MidiService() override = default;

    bool initialize() override;

    void update() override;

    void shutdown() override;

private:

    MidiDeviceManager m_deviceManager;

    std::unique_ptr<MidiInput> m_input;

    std::unique_ptr<ControllerProfile> m_profile;

    std::unique_ptr<MidiProcessor> m_processor;

    Midi14BitProcessor m_14BitProcessor;

    MidiCapture m_capture;
};

} // namespace OpenDJ