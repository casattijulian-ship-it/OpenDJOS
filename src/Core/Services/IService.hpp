#pragma once

namespace OpenDJ
{

class IService
{
public:
    virtual ~IService() = default;

    virtual bool initialize() = 0;

    virtual void shutdown() = 0;
};

} // namespace OpenDJ