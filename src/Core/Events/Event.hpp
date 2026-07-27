#pragma once

#include "EventType.hpp"

#include <string_view>

namespace OpenDJ
{

class Event
{
public:

    virtual ~Event() = default;

    virtual EventType type() const = 0;

    virtual std::string_view name() const = 0;
};

}