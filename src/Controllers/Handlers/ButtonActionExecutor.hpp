#pragma once

#include "ButtonAction.hpp"

namespace OpenDJ
{

class ButtonActionExecutor
{
public:

    void execute(
        const ButtonAction& action);
};

} // namespace OpenDJ