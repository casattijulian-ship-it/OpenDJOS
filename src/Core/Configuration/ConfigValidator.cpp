#include "ConfigValidator.hpp"

namespace OpenDJ
{

bool ConfigValidator::validate(const ConfigData& config) const
{
    if (config.sampleRate() <= 0)
    {
        return false;
    }

    if (config.bufferSize() <= 0)
    {
        return false;
    }

    if (config.musicDirectory().empty())
    {
        return false;
    }

    return true;
}

}