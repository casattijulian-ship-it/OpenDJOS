#include "Core/Application/Application.hpp"

#include <exception>
#include <iostream>

int main()
{
    try
    {
        OpenDJ::Application app;

        return app.run();
    }
    catch (const std::exception& e)
    {
        std::cerr << e.what() << '\n';
        return EXIT_FAILURE;
    }
}