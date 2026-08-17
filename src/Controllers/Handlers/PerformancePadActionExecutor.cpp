#include "PerformancePadActionExecutor.hpp"

#include "Core/Logging/Logger.hpp"

namespace OpenDJ
{

void PerformancePadActionExecutor::execute(
    const PerformancePadAction& action)
{
    if (action.type == PerformancePadActionType::None)
    {
        return;
    }

    std::string deck = "Unknown";

    if (action.deck == Deck::A)
    {
        deck = "A";
    }
    else if (action.deck == Deck::B)
    {
        deck = "B";
    }

    std::string pad = "UNKNOWN";

    switch (action.pad)
    {
        case PerformancePad::Pad1:
            pad = "PAD 1";
            break;

        case PerformancePad::Pad2:
            pad = "PAD 2";
            break;

        case PerformancePad::Pad3:
            pad = "PAD 3";
            break;

        case PerformancePad::Pad4:
            pad = "PAD 4";
            break;

        case PerformancePad::Pad5:
            pad = "PAD 5";
            break;

        case PerformancePad::Pad6:
            pad = "PAD 6";
            break;

        case PerformancePad::Pad7:
            pad = "PAD 7";
            break;

        case PerformancePad::Pad8:
            pad = "PAD 8";
            break;
    }

    std::string actionName = "UNKNOWN";

    switch (action.type)
    {
        case PerformancePadActionType::HotCue:
            actionName = "HOT CUE";
            break;

        case PerformancePadActionType::PadFX1:
            actionName = "PAD FX1";
            break;

        case PerformancePadActionType::BeatJump:
            actionName = "BEAT JUMP";
            break;

        case PerformancePadActionType::Sampler:
            actionName = "SAMPLER";
            break;

        case PerformancePadActionType::Keyboard:
            actionName = "KEYBOARD";
            break;

        case PerformancePadActionType::PadFX2:
            actionName = "PAD FX2";
            break;

        case PerformancePadActionType::BeatLoop:
            actionName = "BEAT LOOP";
            break;

        case PerformancePadActionType::KeyShift:
            actionName = "KEY SHIFT";
            break;

        case PerformancePadActionType::None:
            return;
    }

    const std::string state =
        action.state == ButtonState::Pressed
            ? "PRESSED"
            : "RELEASED";

    Logger::info(
        "PerformancePadActionExecutor -> Deck " +
        deck +
        " | " +
        pad +
        " | " +
        actionName +
        " | " +
        state);
}

} // namespace OpenDJ