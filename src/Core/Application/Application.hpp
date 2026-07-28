#pragma once

#include "../Services/ServiceManager.hpp"

namespace OpenDJ
{

class Application
{
public:

    Application();

    ~Application();

    int run();

private:

    bool initialize();

    void update();

    void shutdown();

private:

    bool m_running = false;

    ServiceManager m_serviceManager;
};

} // namespace OpenDJ