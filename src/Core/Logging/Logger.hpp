#pragma once

#include <string>
#include <string_view>

namespace OpenDJ
{

class Logger
{
public:

    enum class Level
    {
        Debug,
        Info,
        Warning,
        Error
    };

public:

    static void debug(std::string_view message);

    static void info(std::string_view message);

    static void warning(std::string_view message);

    static void error(std::string_view message);

private:

    static void log(Level level, std::string_view message);

    static std::string levelToString(Level level);
};

}