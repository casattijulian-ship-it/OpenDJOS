#include "PerformancePadHandler.hpp"

namespace OpenDJ
{

PerformancePadAction PerformancePadHandler::handle(
    const PerformancePadEvent& event)
{
    PerformancePadAction action;

    action.deck = event.deck();
    action.pad = event.performancePad();
    action.mode = event.padMode();
    action.state = event.state();

    switch (event.padMode())
    {
        case PadMode::HotCue:
            action.type = PerformancePadActionType::HotCue;
            break;

        case PadMode::PadFX1:
            action.type = PerformancePadActionType::PadFX1;
            break;

        case PadMode::BeatJump:
            action.type = PerformancePadActionType::BeatJump;
            break;

        case PadMode::Sampler:
            action.type = PerformancePadActionType::Sampler;
            break;

        case PadMode::Keyboard:
            action.type = PerformancePadActionType::Keyboard;
            break;

        case PadMode::PadFX2:
            action.type = PerformancePadActionType::PadFX2;
            break;

        case PadMode::BeatLoop:
            action.type = PerformancePadActionType::BeatLoop;
            break;

        case PadMode::KeyShift:
            action.type = PerformancePadActionType::KeyShift;
            break;
    }

    m_executor.execute(action);

    return action;
}

} // namespace OpenDJ