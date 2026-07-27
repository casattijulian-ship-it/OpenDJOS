#pragma once

#include "ConfigData.hpp"

namespace OpenDJ
{

class ConfigValidator
{
public:

    ConfigValidator() = default;

    bool validate(const ConfigData& config) const;
};

}