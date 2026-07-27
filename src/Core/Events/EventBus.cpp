#include "EventBus.hpp"

#include "Core/Logging/Logger.hpp"

namespace OpenDJ
{

bool EventBus::initialize()
{
    Logger::info("EventBus initialized.");

    return true;
}

void EventBus::shutdown()
{
    m_listeners.clear();

    Logger::info("EventBus shutdown.");
}

void EventBus::subscribe(EventType type, EventListener listener)
{
    m_listeners[type].push_back(std::move(listener));
}

void EventBus::publish(const Event& event)
{
    Logger::debug(event.name());

    auto it = m_listeners.find(event.type());

    if (it == m_listeners.end())
    {
        return;
    }

    for (const auto& listener : it->second)
    {
        listener(event);
    }
}

}