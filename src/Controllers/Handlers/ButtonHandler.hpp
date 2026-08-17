#pragma once

#include "../Mapping/ButtonEvent.hpp"
#include "ButtonAction.hpp"

namespace OpenDJ
{

class ButtonHandler
{
public:

    ButtonAction handle(
        const ButtonEvent& event);
};

} // namespace OpenDJ