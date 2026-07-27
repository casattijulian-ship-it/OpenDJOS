#include "ServiceManager.hpp"

namespace OpenDJ
{

bool ServiceManager::initialize()
{
    if (!m_eventBus.initialize())
    {
        return false;
    }

    return true;
}

void ServiceManager::shutdown()
{
    m_eventBus.shutdown();
}

EventBus& ServiceManager::eventBus()
{
    return m_eventBus;
}

}