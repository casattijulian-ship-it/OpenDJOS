#pragma once

#include "Event.hpp"

#include <functional>

namespace OpenDJ
{

using EventListener = std::function<void(const Event&)>;

}