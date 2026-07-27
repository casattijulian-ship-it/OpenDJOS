#pragma once

#include <string>

namespace OpenDJ
{

class Version
{
public:

    static std::string name();

    static std::string version();

    static std::string codename();

    static std::string fullVersion();
};

}