#include "ServiceManager.hpp"

namespace OpenDJ
{

bool ServiceManager::initialize()
{
    // Inicializar EventBus
    if (!m_eventBus.initialize())
    {
        return false;
    }

    // Inicializar servicio MIDI
    if (!m_midiService.initialize())
    {
        m_eventBus.shutdown();

        return false;
    }

    return true;
}

void ServiceManager::update()
{
    m_midiService.update();
}

void ServiceManager::shutdown()
{
    m_midiService.shutdown();

    m_eventBus.shutdown();
}

EventBus& ServiceManager::eventBus()
{
    return m_eventBus;
}

} // namespace OpenDJ