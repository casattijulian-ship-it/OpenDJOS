#pragma once

#include "ConfigData.hpp"
#include "ConfigLoader.hpp"
#include "ConfigValidator.hpp"

namespace OpenDJ
{

class Configuration
{
public:

    static Configuration& instance();

    bool initialize();

    const ConfigData& data() const;

private:

    Configuration() = default;

private:

    ConfigData m_data;
    ConfigLoader m_loader;
    ConfigValidator m_validator;
};

}