#pragma once

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

    void shutdown();
};

}