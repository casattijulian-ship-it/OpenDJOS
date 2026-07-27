#include "Version.hpp"

namespace OpenDJ
{

std::string Version::name()
{
    return "OpenDJ OS";
}

std::string Version::version()
{
    return "0.1.0";
}

std::string Version::codename()
{
    return "Alpha";
}

std::string Version::fullVersion()
{
    return name() + " " + version() + " " + codename();
}

}