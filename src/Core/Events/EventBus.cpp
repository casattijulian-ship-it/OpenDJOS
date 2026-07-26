#include "EventBus.hpp"
#include "Core/Logging/Logger.hpp"

namespace OpenDJ
{

bool EventBus::initialize()
{
    Logger logger;
    logger.info("Event Bus initialized.");

    return true;
}

void EventBus::shutdown()
{
    Logger logger;
    logger.info("Event Bus shutdown.");
}

void EventBus::publish(const Event& event)
{
    Logger logger;
    logger.debug(event.name());
}

}