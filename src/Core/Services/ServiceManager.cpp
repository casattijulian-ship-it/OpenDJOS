#include "ServiceManager.hpp"

namespace OpenDJ
{

bool ServiceManager::initialize()
{
    if (!m_logger.initialize())
    {
        return false;
    }

    if (!m_eventBus.initialize())
    {
        return false;
    }

    return true;
}

void ServiceManager::shutdown()
{
    m_eventBus.shutdown();
    m_logger.shutdown();
}

Logger& ServiceManager::logger()
{
    return m_logger;
}

EventBus& ServiceManager::eventBus()
{
    return m_eventBus;
}

}