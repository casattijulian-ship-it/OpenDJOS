#pragma once

#include "Core/Services/ServiceManager.hpp"

namespace OpenDJ
{

class Application
{
public:
    Application() = default;
    ~Application() = default;

    int run();

private:
    bool initialize();
    void shutdown();

private:
    ServiceManager m_services;
};

}