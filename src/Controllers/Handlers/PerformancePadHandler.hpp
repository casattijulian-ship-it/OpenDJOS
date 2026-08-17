#pragma once

#include "../Mapping/PerformancePadEvent.hpp"
#include "PerformancePadAction.hpp"
#include "PerformancePadActionExecutor.hpp"

namespace OpenDJ
{

class PerformancePadHandler
{
public:

    PerformancePadHandler() = default;

    PerformancePadAction handle(
        const PerformancePadEvent& event);

private:

    PerformancePadActionExecutor m_executor;
};

} // namespace OpenDJ