#pragma once

#include "../Types/Deck.hpp"
#include "../Types/Button.hpp"
#include "../Types/ButtonState.hpp"

namespace OpenDJ
{

enum class ButtonActionType
{
    None,

    Play,
    Cue,
    Sync,
    Shift,
    Load,
    Browse,

    HotCue1,
    HotCue2,
    HotCue3,
    HotCue4,

    LoopIn,
    LoopOut,
    ReloopExit,

    BeatJumpForward,
    BeatJumpBackward
};

struct ButtonAction
{
    ButtonActionType type =
        ButtonActionType::None;

    Deck deck =
        Deck::None;

    Button button =
        Button::Play;

    ButtonState state =
        ButtonState::Released;
};

} // namespace OpenDJ