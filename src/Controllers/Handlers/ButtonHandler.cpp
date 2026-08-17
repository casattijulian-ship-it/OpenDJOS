#include "ButtonHandler.hpp"

namespace OpenDJ
{

ButtonAction ButtonHandler::handle(
    const ButtonEvent& event)
{
    ButtonAction action;

    action.deck = event.deck();
    action.button = event.button();
    action.state = event.state();

    switch (event.button())
    {
        case Button::Play:
            action.type = ButtonActionType::Play;
            break;

        case Button::Cue:
            action.type = ButtonActionType::Cue;
            break;

        case Button::Sync:
            action.type = ButtonActionType::Sync;
            break;

        case Button::Shift:
            action.type = ButtonActionType::Shift;
            break;

        case Button::Load:
            action.type = ButtonActionType::Load;
            break;

        case Button::Browse:
            action.type = ButtonActionType::Browse;
            break;

        case Button::HotCue1:
            action.type = ButtonActionType::HotCue1;
            break;

        case Button::HotCue2:
            action.type = ButtonActionType::HotCue2;
            break;

        case Button::HotCue3:
            action.type = ButtonActionType::HotCue3;
            break;

        case Button::HotCue4:
            action.type = ButtonActionType::HotCue4;
            break;

        case Button::LoopIn:
            action.type = ButtonActionType::LoopIn;
            break;

        case Button::LoopOut:
            action.type = ButtonActionType::LoopOut;
            break;

        case Button::ReloopExit:
            action.type = ButtonActionType::ReloopExit;
            break;

        case Button::BeatJumpForward:
            action.type = ButtonActionType::BeatJumpForward;
            break;

        case Button::BeatJumpBackward:
            action.type = ButtonActionType::BeatJumpBackward;
            break;

        case Button::Unknown:
            action.type = ButtonActionType::None;
            break;
    }

    return action;
}

} // namespace OpenDJ