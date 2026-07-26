#pragma once

#include <string_view>

namespace OpenDJ
{
    class Version
    {
    public:
        static std::string_view name();
        static std::string_view version();
        static std::string_view fullVersion();
    };
}