#pragma once

#include "Core/Events/Event.hpp"

namespace OpenDJ
{

class ControllerEvent : public Event
{
public:

    ~ControllerEvent() override = default;
};

}