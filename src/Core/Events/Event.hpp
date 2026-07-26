#pragma once

#include <string_view>

namespace OpenDJ
{

class Event
{
public:
    virtual ~Event() = default;

    virtual std::string_view name() const = 0;
};

}