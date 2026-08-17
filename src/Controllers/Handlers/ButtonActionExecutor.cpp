#include "ButtonActionExecutor.hpp"

#include "Core/Logging/Logger.hpp"

namespace OpenDJ
{

void ButtonActionExecutor::execute(
    const ButtonAction& action)
{
    if (action.type == ButtonActionType::None)
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

    std::string button = "UNKNOWN";

    switch (action.type)
    {
        case ButtonActionType::Play:
            button = "PLAY";
            break;

        case ButtonActionType::Cue:
            button = "CUE";
            break;

        case ButtonActionType::Sync:
            button = "SYNC";
            break;

        case ButtonActionType::Shift:
            button = "SHIFT";
            break;

        case ButtonActionType::Load:
            button = "LOAD";
            break;

        case ButtonActionType::Browse:
            button = "BROWSE";
            break;

        case ButtonActionType::HotCue1:
            button = "HOT CUE 1";
            break;

        case ButtonActionType::HotCue2:
            button = "HOT CUE 2";
            break;

        case ButtonActionType::HotCue3:
            button = "HOT CUE 3";
            break;

        case ButtonActionType::HotCue4:
            button = "HOT CUE 4";
            break;

        case ButtonActionType::LoopIn:
            button = "LOOP IN";
            break;

        case ButtonActionType::LoopOut:
            button = "LOOP OUT";
            break;

        case ButtonActionType::ReloopExit:
            button = "RELOOP/EXIT";
            break;

        case ButtonActionType::BeatJumpForward:
            button = "BEAT JUMP FORWARD";
            break;

        case ButtonActionType::BeatJumpBackward:
            button = "BEAT JUMP BACKWARD";
            break;

        case ButtonActionType::None:
            return;
    }

    const std::string state =
        action.state == ButtonState::Pressed
            ? "PRESSED"
            : "RELEASED";

    Logger::info(
        "ButtonActionExecutor -> Deck " +
        deck +
        " | " +
        button +
        " | " +
        state);
}

} // namespace OpenDJ