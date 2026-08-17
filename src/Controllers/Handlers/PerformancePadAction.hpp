#pragma once

#include "../Types/Deck.hpp"
#include "../Types/PerformancePad.hpp"
#include "../Types/PadMode.hpp"
#include "../Mapping/ButtonEvent.hpp"

namespace OpenDJ
{

enum class PerformancePadActionType
{
    None,

    HotCue,
    PadFX1,
    BeatJump,
    Sampler,
    Keyboard,
    PadFX2,
    BeatLoop,
    KeyShift
};

struct PerformancePadAction
{
    PerformancePadActionType type =
        PerformancePadActionType::None;

    Deck deck = Deck::None;

    PerformancePad pad = PerformancePad::Pad1;

    PadMode mode = PadMode::HotCue;

    ButtonState state = ButtonState::Released;
};

} // namespace OpenDJ