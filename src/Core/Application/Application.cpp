#include "Application.hpp"

#include "../Configuration/Configuration.hpp"
#include "../Logging/Logger.hpp"
#include "../Version/Version.hpp"

#include <chrono>
#include <thread>

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

    m_running = true;

    while (m_running)
    {
        update();
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

    Logger::info("Initializing services...");

    if (!m_serviceManager.initialize())
    {
        Logger::error("Failed to initialize services.");
        return false;
    }

    Logger::info("Services initialized successfully.");

    Logger::info("==================================");

    return true;
}

void Application::update()
{
    m_serviceManager.update();

    std::this_thread::sleep_for(
        std::chrono::milliseconds(1));
}

void Application::shutdown()
{
    Logger::info("Shutting down OpenDJ OS...");

    m_serviceManager.shutdown();
}

} // namespace OpenDJ