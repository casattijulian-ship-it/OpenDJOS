#pragma once

#include "Core/Events/EventBus.hpp"
#include "MidiService.hpp"

#include "Controllers/Handlers/PerformancePadHandler.hpp"
#include "Controllers/Handlers/ButtonHandler.hpp"
#include "Controllers/Handlers/ButtonActionExecutor.hpp"
#include "Controllers/Handlers/JogWheelHandler.hpp"
#include "Controllers/Handlers/JogWheelActionExecutor.hpp"

namespace OpenDJ
{

class ServiceManager
{
public:

    ServiceManager();

    ~ServiceManager() = default;

    bool initialize();

    void update();

    void shutdown();

    EventBus& eventBus();

private:

    EventBus m_eventBus;

    MidiService m_midiService;

    PerformancePadHandler m_performancePadHandler;

    ButtonHandler m_buttonHandler;

    ButtonActionExecutor m_buttonActionExecutor;

    JogWheelHandler m_jogWheelHandler;

    JogWheelActionExecutor m_jogWheelActionExecutor;
};

} // namespace OpenDJ