#pragma once

#include "Core/Events/EventBus.hpp"
#include "MidiService.hpp"

namespace OpenDJ
{

class ServiceManager
{
public:

    ServiceManager() = default;

    ~ServiceManager() = default;

    bool initialize();

    void update();

    void shutdown();

    EventBus& eventBus();

private:

    EventBus m_eventBus;

    MidiService m_midiService;
};

} // namespace OpenDJ