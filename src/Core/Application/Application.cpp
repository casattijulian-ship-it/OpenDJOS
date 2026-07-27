#include "Application.hpp"

#include "../Configuration/Configuration.hpp"
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

    Logger::info("Loading configuration...");

    if (!Configuration::instance().initialize())
    {
        Logger::error("Failed to load configuration.");
        return false;
    }

    Logger::info("Configuration loaded successfully.");
    Logger::info("==================================");

    return true;
}

void Application::shutdown()
{
    Logger::info("Shutting down OpenDJ OS...");
}

}