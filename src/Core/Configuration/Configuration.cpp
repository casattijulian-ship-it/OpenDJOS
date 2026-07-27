#include "Configuration.hpp"

namespace OpenDJ
{

Configuration& Configuration::instance()
{
    static Configuration instance;
    return instance;
}

bool Configuration::initialize()
{
    if (!m_loader.load(m_data))
    {
        return false;
    }

    if (!m_validator.validate(m_data))
    {
        return false;
    }

    return true;
}

const ConfigData& Configuration::data() const
{
    return m_data;
}

}