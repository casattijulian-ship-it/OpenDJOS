#include "Logger.hpp"

#include <iostream>

namespace OpenDJ
{

void Logger::debug(std::string_view message)
{
    log(Level::Debug, message);
}

void Logger::info(std::string_view message)
{
    log(Level::Info, message);
}

void Logger::warning(std::string_view message)
{
    log(Level::Warning, message);
}

void Logger::error(std::string_view message)
{
    log(Level::Error, message);
}

void Logger::log(Level level, std::string_view message)
{
    std::cout
        << "["
        << levelToString(level)
        << "] "
        << message
        << std::endl;
}

std::string Logger::levelToString(Level level)
{
    switch (level)
    {
        case Level::Debug:
            return "DEBUG";

        case Level::Info:
            return "INFO";

        case Level::Warning:
            return "WARNING";

        case Level::Error:
            return "ERROR";

        default:
            return "UNKNOWN";
    }
}

}