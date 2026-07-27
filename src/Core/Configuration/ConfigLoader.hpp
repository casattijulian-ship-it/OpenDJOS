#pragma once

#include "ConfigData.hpp"

namespace OpenDJ
{

class ConfigLoader
{
public:

    ConfigLoader() = default;

    bool load(ConfigData& config);
};

}