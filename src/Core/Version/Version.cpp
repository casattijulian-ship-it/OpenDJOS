#include "Version.hpp"

namespace OpenDJ
{
    std::string_view Version::name()
    {
        return "OpenDJ OS";
    }

    std::string_view Version::version()
    {
        return "0.1.0";
    }

    std::string_view Version::fullVersion()
    {
        return "OpenDJ OS 0.1.0";
    }
}