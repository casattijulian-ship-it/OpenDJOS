#pragma once

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

    EventBus& eventBus();

private:

    EventBus m_eventBus;
};

}