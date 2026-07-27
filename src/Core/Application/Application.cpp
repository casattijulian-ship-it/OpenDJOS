#include "Application.hpp"

#include "../Logging/Logger.hpp"
#include "../Version/Version.hpp"

namespace OpenDJ
{

Application::Application()
{
}

Application::~Application()
{
}

int Application::run()
{
    if (!initialize())
    {
        return -1;
    }

    shutdown();

    return 0;
}

bool Application::initialize()
{
    Logger::info("==================================");
    Logger::info(Version::fullVersion());
    Logger::info("Initializing OpenDJ OS...");
    Logger::info("==================================");

    return true;
}

void Application::shutdown()
{
    Logger::info("Shutting down OpenDJ OS...");
}

}