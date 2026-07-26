#pragma once

#include "Core/Logging/Logger.hpp"
#include "Core/Events/EventBus.hpp"

namespace OpenDJ
{

class ServiceManager
{
public:
    ServiceManager() = default;
    ~ServiceManager() = default;

    bool initialize();
    void shutdown();

    Logger& logger();
    EventBus& eventBus();

private:
    Logger m_logger;
    EventBus m_eventBus;
};

} // namespace OpenDJ