#include "Application.hpp"

#include "Core/Version/Version.hpp"

namespace OpenDJ
{

int Application::run()
{
    if (!initialize())
    {
        return -1;
    }

    m_services.logger().info("Application started");

    shutdown();

    return 0;
}

bool Application::initialize()
{
    if (!m_services.initialize())
    {
        return false;
    }

    m_services.logger().info(Version::fullVersion());
    m_services.logger().info("Initializing OpenDJ OS...");

    return true;
}

void Application::shutdown()
{
    m_services.logger().info("Shutting down OpenDJ OS...");

    m_services.shutdown();
}

}