#include "Logger.hpp"

#include <iostream>

namespace OpenDJ
{

bool Logger::initialize()
{
    std::cout << "[INFO] Logger initialized." << std::endl;
    return true;
}

void Logger::shutdown()
{
    std::cout << "[INFO] Logger shutdown." << std::endl;
}

void Logger::info(std::string_view message)
{
    std::cout << "[INFO] " << message << std::endl;
}

void Logger::warning(std::string_view message)
{
    std::cout << "[WARNING] " << message << std::endl;
}

void Logger::error(std::string_view message)
{
    std::cout << "[ERROR] " << message << std::endl;
}

void Logger::debug(std::string_view message)
{
    std::cout << "[DEBUG] " << message << std::endl;
}

}