#include "DDJ400Profile.hpp"

#include "DDJ400Definitions.hpp"

#include "../Types/Button.hpp"
#include "../Types/ButtonState.hpp"
#include "../Types/Deck.hpp"
#include "../Types/Fader.hpp"
#include "../Types/Knob.hpp"
#include "../Types/PerformancePad.hpp"
#include "../Types/PadMode.hpp"

namespace OpenDJ
{

DDJ400Profile::DDJ400Profile()
{
    // ============================================================
    // TRANSPORT - DECK A
    // ============================================================

    // PLAY
    addEntry({
        MidiMessageType::NoteOn,
        DDJ400::Channel::DeckA,
        DDJ400::Transport::Play,
        {
            ControllerActionType::Button,
            Deck::A,
            Button::Play,
            Fader::Channel,
            Knob::Trim,
            ButtonState::Pressed,
            0
        }
    });
    addEntry({
        MidiMessageType::NoteOff,
        DDJ400::Channel::DeckA,
        DDJ400::Transport::Play,
        {
            ControllerActionType::Button,
            Deck::A,
            Button::Play,
            Fader::Channel,
            Knob::Trim,
            ButtonState::Released,
            0
        }
    });

    // CUE
    addEntry({
        MidiMessageType::NoteOn,
        DDJ400::Channel::DeckA,
        DDJ400::Transport::Cue,
        {
            ControllerActionType::Button,
            Deck::A,
            Button::Cue,
            Fader::Channel,
            Knob::Trim,
            ButtonState::Pressed,
            0
        }
    });

    addEntry({
        MidiMessageType::NoteOff,
        DDJ400::Channel::DeckA,
        DDJ400::Transport::Cue,
        {
            ControllerActionType::Button,
            Deck::A,
            Button::Cue,
            Fader::Channel,
            Knob::Trim,
            ButtonState::Released,
            0
        }
    });

    // SYNC
    addEntry({
        MidiMessageType::NoteOn,
        DDJ400::Channel::DeckA,
        DDJ400::Transport::BeatSync,
        {
            ControllerActionType::Button,
            Deck::A,
            Button::Sync,
            Fader::Channel,
            Knob::Trim,
            ButtonState::Pressed,
            0
        }
    });

    addEntry({
        MidiMessageType::NoteOff,
        DDJ400::Channel::DeckA,
        DDJ400::Transport::BeatSync,
        {
            ControllerActionType::Button,
            Deck::A,
            Button::Sync,
            Fader::Channel,
            Knob::Trim,
            ButtonState::Released,
            0
        }
    });

    // LOOP IN
    addEntry({
        MidiMessageType::NoteOn,
        DDJ400::Channel::DeckA,
        DDJ400::Transport::LoopIn,
        {
            ControllerActionType::Button,
            Deck::A,
            Button::LoopIn,
            Fader::Channel,
            Knob::Trim,
            ButtonState::Pressed,
            0
        }
    });

    addEntry({
        MidiMessageType::NoteOff,
        DDJ400::Channel::DeckA,
        DDJ400::Transport::LoopIn,
        {
            ControllerActionType::Button,
            Deck::A,
            Button::LoopIn,
            Fader::Channel,
            Knob::Trim,
            ButtonState::Released,
            0
        }
    });

    // LOOP OUT
    addEntry({
        MidiMessageType::NoteOn,
        DDJ400::Channel::DeckA,
        DDJ400::Transport::LoopOut,
        {
            ControllerActionType::Button,
            Deck::A,
            Button::LoopOut,
            Fader::Channel,
            Knob::Trim,
            ButtonState::Pressed,
            0
        }
    });

    addEntry({
        MidiMessageType::NoteOff,
        DDJ400::Channel::DeckA,
        DDJ400::Transport::LoopOut,
        {
            ControllerActionType::Button,
            Deck::A,
            Button::LoopOut,
            Fader::Channel,
            Knob::Trim,
            ButtonState::Released,
            0
        }
    });

    // RELOOP / EXIT
    addEntry({
        MidiMessageType::NoteOn,
        DDJ400::Channel::DeckA,
        DDJ400::Transport::ReloopExit,
        {
            ControllerActionType::Button,
            Deck::A,
            Button::ReloopExit,
            Fader::Channel,
            Knob::Trim,
            ButtonState::Pressed,
            0
        }
    });

    addEntry({
        MidiMessageType::NoteOff,
        DDJ400::Channel::DeckA,
        DDJ400::Transport::ReloopExit,
        {
            ControllerActionType::Button,
            Deck::A,
            Button::ReloopExit,
            Fader::Channel,
            Knob::Trim,
            ButtonState::Released,
            0
        }
    });

    // SHIFT
    addEntry({
        MidiMessageType::NoteOn,
        DDJ400::Channel::DeckA,
        DDJ400::Transport::Shift,
        {
            ControllerActionType::Button,
            Deck::A,
            Button::Shift,
            Fader::Channel,
            Knob::Trim,
            ButtonState::Pressed,
            0
        }
    });

    addEntry({
        MidiMessageType::NoteOff,
        DDJ400::Channel::DeckA,
        DDJ400::Transport::Shift,
        {
            ControllerActionType::Button,
            Deck::A,
            Button::Shift,
            Fader::Channel,
            Knob::Trim,
            ButtonState::Released,
            0
        }
    });

    // ============================================================
    // TRANSPORT - DECK B
    // ============================================================

    // PLAY
    addEntry({
        MidiMessageType::NoteOn,
        DDJ400::Channel::DeckB,
        DDJ400::Transport::Play,
        {
            ControllerActionType::Button,
            Deck::B,
            Button::Play,
            Fader::Channel,
            Knob::Trim,
            ButtonState::Pressed,
            0
        }
    });

    addEntry({
        MidiMessageType::NoteOff,
        DDJ400::Channel::DeckB,
        DDJ400::Transport::Play,
        {
            ControllerActionType::Button,
            Deck::B,
            Button::Play,
            Fader::Channel,
            Knob::Trim,
            ButtonState::Released,
            0
        }
    });

    // CUE
    addEntry({
        MidiMessageType::NoteOn,
        DDJ400::Channel::DeckB,
        DDJ400::Transport::Cue,
        {
            ControllerActionType::Button,
            Deck::B,
            Button::Cue,
            Fader::Channel,
            Knob::Trim,
            ButtonState::Pressed,
            0
        }
    });

    addEntry({
        MidiMessageType::NoteOff,
        DDJ400::Channel::DeckB,
        DDJ400::Transport::Cue,
        {
            ControllerActionType::Button,
            Deck::B,
            Button::Cue,
            Fader::Channel,
            Knob::Trim,
            ButtonState::Released,
            0
        }
    });

    // SYNC
    addEntry({
        MidiMessageType::NoteOn,
        DDJ400::Channel::DeckB,
        DDJ400::Transport::BeatSync,
        {
            ControllerActionType::Button,
            Deck::B,
            Button::Sync,
            Fader::Channel,
            Knob::Trim,
            ButtonState::Pressed,
            0
        }
    });

    addEntry({
        MidiMessageType::NoteOff,
        DDJ400::Channel::DeckB,
        DDJ400::Transport::BeatSync,
        {
            ControllerActionType::Button,
            Deck::B,
            Button::Sync,
            Fader::Channel,
            Knob::Trim,
            ButtonState::Released,
            0
        }
    });

    // LOOP IN
    addEntry({
        MidiMessageType::NoteOn,
        DDJ400::Channel::DeckB,
        DDJ400::Transport::LoopIn,
        {
            ControllerActionType::Button,
            Deck::B,
            Button::LoopIn,
            Fader::Channel,
            Knob::Trim,
            ButtonState::Pressed,
            0
        }
    });

    addEntry({
        MidiMessageType::NoteOff,
        DDJ400::Channel::DeckB,
        DDJ400::Transport::LoopIn,
        {
            ControllerActionType::Button,
            Deck::B,
            Button::LoopIn,
            Fader::Channel,
            Knob::Trim,
            ButtonState::Released,
            0
        }
    });

    // LOOP OUT
    addEntry({
        MidiMessageType::NoteOn,
        DDJ400::Channel::DeckB,
        DDJ400::Transport::LoopOut,
        {
            ControllerActionType::Button,
            Deck::B,
            Button::LoopOut,
            Fader::Channel,
            Knob::Trim,
            ButtonState::Pressed,
            0
        }
    });

    addEntry({
        MidiMessageType::NoteOff,
        DDJ400::Channel::DeckB,
        DDJ400::Transport::LoopOut,
        {
            ControllerActionType::Button,
            Deck::B,
            Button::LoopOut,
            Fader::Channel,
            Knob::Trim,
            ButtonState::Released,
            0
        }
    });

    // RELOOP / EXIT
    addEntry({
        MidiMessageType::NoteOn,
        DDJ400::Channel::DeckB,
        DDJ400::Transport::ReloopExit,
        {
            ControllerActionType::Button,
            Deck::B,
            Button::ReloopExit,
            Fader::Channel,
            Knob::Trim,
            ButtonState::Pressed,
            0
        }
    });

    addEntry({
        MidiMessageType::NoteOff,
        DDJ400::Channel::DeckB,
        DDJ400::Transport::ReloopExit,
        {
            ControllerActionType::Button,
            Deck::B,
            Button::ReloopExit,
            Fader::Channel,
            Knob::Trim,
            ButtonState::Released,
            0
        }
    });

    // SHIFT
    addEntry({
        MidiMessageType::NoteOn,
        DDJ400::Channel::DeckB,
        DDJ400::Transport::Shift,
        {
            ControllerActionType::Button,
            Deck::B,
            Button::Shift,
            Fader::Channel,
            Knob::Trim,
            ButtonState::Pressed,
            0
        }
    });

    addEntry({
        MidiMessageType::NoteOff,
        DDJ400::Channel::DeckB,
        DDJ400::Transport::Shift,
        {
            ControllerActionType::Button,
            Deck::B,
            Button::Shift,
            Fader::Channel,
            Knob::Trim,
            ButtonState::Released,
            0
        }
    });

    // ============================================================
    // PERFORMANCE PADS - HOT CUE
    // ============================================================

    // DECK A
    addEntry({
        MidiMessageType::NoteOn,
        DDJ400::Channel::PadA,
        DDJ400::PerformancePad::HotCueBase + 0,
        {
            ControllerActionType::PerformancePad,
            Deck::A,
            Button::Unknown,
            Fader::Channel,
            Knob::Trim,
            ButtonState::Released,
            0,
            Encoder::Browse,
            JogWheel::Platter,
            JogTouchState::Released,
            PerformancePad::Pad1,
            PadMode::HotCue
        }
    });

    addEntry({
        MidiMessageType::NoteOn,
        DDJ400::Channel::PadA,
        DDJ400::PerformancePad::HotCueBase + 1,
        {
            ControllerActionType::PerformancePad,
            Deck::A,
            Button::Unknown,
            Fader::Channel,
            Knob::Trim,
            ButtonState::Released,
            0,
            Encoder::Browse,
            JogWheel::Platter,
            JogTouchState::Released,
            PerformancePad::Pad2,
            PadMode::HotCue
        }
    });

    addEntry({
        MidiMessageType::NoteOn,
        DDJ400::Channel::PadA,
        DDJ400::PerformancePad::HotCueBase + 2,
        {
            ControllerActionType::PerformancePad,
            Deck::A,
            Button::Unknown,
            Fader::Channel,
            Knob::Trim,
            ButtonState::Released,
            0,
            Encoder::Browse,
            JogWheel::Platter,
            JogTouchState::Released,
            PerformancePad::Pad3,
            PadMode::HotCue
        }
    });

    addEntry({
        MidiMessageType::NoteOn,
        DDJ400::Channel::PadA,
        DDJ400::PerformancePad::HotCueBase + 3,
        {
            ControllerActionType::PerformancePad,
            Deck::A,
            Button::Unknown,
            Fader::Channel,
            Knob::Trim,
            ButtonState::Released,
            0,
            Encoder::Browse,
            JogWheel::Platter,
            JogTouchState::Released,
            PerformancePad::Pad4,
            PadMode::HotCue
        }
    });

    addEntry({
        MidiMessageType::NoteOn,
        DDJ400::Channel::PadA,
        DDJ400::PerformancePad::HotCueBase + 4,
        {
            ControllerActionType::PerformancePad,
            Deck::A,
            Button::Unknown,
            Fader::Channel,
            Knob::Trim,
            ButtonState::Released,
            0,
            Encoder::Browse,
            JogWheel::Platter,
            JogTouchState::Released,
            PerformancePad::Pad5,
            PadMode::HotCue
        }
    });

    addEntry({
        MidiMessageType::NoteOn,
        DDJ400::Channel::PadA,
        DDJ400::PerformancePad::HotCueBase + 5,
        {
            ControllerActionType::PerformancePad,
            Deck::A,
            Button::Unknown,
            Fader::Channel,
            Knob::Trim,
            ButtonState::Released,
            0,
            Encoder::Browse,
            JogWheel::Platter,
            JogTouchState::Released,
            PerformancePad::Pad6,
            PadMode::HotCue
        }
    });

    addEntry({
        MidiMessageType::NoteOn,
        DDJ400::Channel::PadA,
        DDJ400::PerformancePad::HotCueBase + 6,
        {
            ControllerActionType::PerformancePad,
            Deck::A,
            Button::Unknown,
            Fader::Channel,
            Knob::Trim,
            ButtonState::Released,
            0,
            Encoder::Browse,
            JogWheel::Platter,
            JogTouchState::Released,
            PerformancePad::Pad7,
            PadMode::HotCue
        }
    });

    addEntry({
        MidiMessageType::NoteOn,
        DDJ400::Channel::PadA,
        DDJ400::PerformancePad::HotCueBase + 7,
        {
            ControllerActionType::PerformancePad,
            Deck::A,
            Button::Unknown,
            Fader::Channel,
            Knob::Trim,
            ButtonState::Released,
            0,
            Encoder::Browse,
            JogWheel::Platter,
            JogTouchState::Released,
            PerformancePad::Pad8,
            PadMode::HotCue
        }
    });

    // DECK B
    addEntry({
        MidiMessageType::NoteOn,
        DDJ400::Channel::PadB,
        DDJ400::PerformancePad::HotCueBase + 0,
        {
            ControllerActionType::PerformancePad,
            Deck::B,
            Button::Unknown,
            Fader::Channel,
            Knob::Trim,
            ButtonState::Released,
            0,
            Encoder::Browse,
            JogWheel::Platter,
            JogTouchState::Released,
            PerformancePad::Pad1,
            PadMode::HotCue
        }
    });

    addEntry({
        MidiMessageType::NoteOn,
        DDJ400::Channel::PadB,
        DDJ400::PerformancePad::HotCueBase + 1,
        {
            ControllerActionType::PerformancePad,
            Deck::B,
            Button::Unknown,
            Fader::Channel,
            Knob::Trim,
            ButtonState::Released,
            0,
            Encoder::Browse,
            JogWheel::Platter,
            JogTouchState::Released,
            PerformancePad::Pad2,
            PadMode::HotCue
        }
    });

    addEntry({
        MidiMessageType::NoteOn,
        DDJ400::Channel::PadB,
        DDJ400::PerformancePad::HotCueBase + 2,
        {
            ControllerActionType::PerformancePad,
            Deck::B,
            Button::Unknown,
            Fader::Channel,
            Knob::Trim,
            ButtonState::Released,
            0,
            Encoder::Browse,
            JogWheel::Platter,
            JogTouchState::Released,
            PerformancePad::Pad3,
            PadMode::HotCue
        }
    });

    addEntry({
        MidiMessageType::NoteOn,
        DDJ400::Channel::PadB,
        DDJ400::PerformancePad::HotCueBase + 3,
        {
            ControllerActionType::PerformancePad,
            Deck::B,
            Button::Unknown,
            Fader::Channel,
            Knob::Trim,
            ButtonState::Released,
            0,
            Encoder::Browse,
            JogWheel::Platter,
            JogTouchState::Released,
            PerformancePad::Pad4,
            PadMode::HotCue
        }
    });

    addEntry({
        MidiMessageType::NoteOn,
        DDJ400::Channel::PadB,
        DDJ400::PerformancePad::HotCueBase + 4,
        {
            ControllerActionType::PerformancePad,
            Deck::B,
            Button::Unknown,
            Fader::Channel,
            Knob::Trim,
            ButtonState::Released,
            0,
            Encoder::Browse,
            JogWheel::Platter,
            JogTouchState::Released,
            PerformancePad::Pad5,
            PadMode::HotCue
        }
    });

    addEntry({
        MidiMessageType::NoteOn,
        DDJ400::Channel::PadB,
        DDJ400::PerformancePad::HotCueBase + 5,
        {
            ControllerActionType::PerformancePad,
            Deck::B,
            Button::Unknown,
            Fader::Channel,
            Knob::Trim,
            ButtonState::Released,
            0,
            Encoder::Browse,
            JogWheel::Platter,
            JogTouchState::Released,
            PerformancePad::Pad6,
            PadMode::HotCue
        }
    });

    addEntry({
        MidiMessageType::NoteOn,
        DDJ400::Channel::PadB,
        DDJ400::PerformancePad::HotCueBase + 6,
        {
            ControllerActionType::PerformancePad,
            Deck::B,
            Button::Unknown,
            Fader::Channel,
            Knob::Trim,
            ButtonState::Released,
            0,
            Encoder::Browse,
            JogWheel::Platter,
            JogTouchState::Released,
            PerformancePad::Pad7,
            PadMode::HotCue
        }
    });

    addEntry({
        MidiMessageType::NoteOn,
        DDJ400::Channel::PadB,
        DDJ400::PerformancePad::HotCueBase + 7,
        {
            ControllerActionType::PerformancePad,
            Deck::B,
            Button::Unknown,
            Fader::Channel,
            Knob::Trim,
            ButtonState::Released,
            0,
            Encoder::Browse,
            JogWheel::Platter,
            JogTouchState::Released,
            PerformancePad::Pad8,
            PadMode::HotCue
        }
    });

    // ============================================================
// PERFORMANCE PADS - BEAT JUMP
// ============================================================

// DECK A
addEntry({
    MidiMessageType::NoteOn,
    DDJ400::Channel::PadA,
    DDJ400::PerformancePad::BeatJumpBase + 0,
    {
        ControllerActionType::PerformancePad,
        Deck::A,
        Button::Unknown,
        Fader::Channel,
        Knob::Trim,
        ButtonState::Released,
        0,
        Encoder::Browse,
        JogWheel::Platter,
        JogTouchState::Released,
        PerformancePad::Pad1,
        PadMode::BeatJump
    }
});

addEntry({
    MidiMessageType::NoteOn,
    DDJ400::Channel::PadA,
    DDJ400::PerformancePad::BeatJumpBase + 1,
    {
        ControllerActionType::PerformancePad,
        Deck::A,
        Button::Unknown,
        Fader::Channel,
        Knob::Trim,
        ButtonState::Released,
        0,
        Encoder::Browse,
        JogWheel::Platter,
        JogTouchState::Released,
        PerformancePad::Pad2,
        PadMode::BeatJump
    }
});

addEntry({
    MidiMessageType::NoteOn,
    DDJ400::Channel::PadA,
    DDJ400::PerformancePad::BeatJumpBase + 2,
    {
        ControllerActionType::PerformancePad,
        Deck::A,
        Button::Unknown,
        Fader::Channel,
        Knob::Trim,
        ButtonState::Released,
        0,
        Encoder::Browse,
        JogWheel::Platter,
        JogTouchState::Released,
        PerformancePad::Pad3,
        PadMode::BeatJump
    }
});

addEntry({
    MidiMessageType::NoteOn,
    DDJ400::Channel::PadA,
    DDJ400::PerformancePad::BeatJumpBase + 3,
    {
        ControllerActionType::PerformancePad,
        Deck::A,
        Button::Unknown,
        Fader::Channel,
        Knob::Trim,
        ButtonState::Released,
        0,
        Encoder::Browse,
        JogWheel::Platter,
        JogTouchState::Released,
        PerformancePad::Pad4,
        PadMode::BeatJump
    }
});

addEntry({
    MidiMessageType::NoteOn,
    DDJ400::Channel::PadA,
    DDJ400::PerformancePad::BeatJumpBase + 4,
    {
        ControllerActionType::PerformancePad,
        Deck::A,
        Button::Unknown,
        Fader::Channel,
        Knob::Trim,
        ButtonState::Released,
        0,
        Encoder::Browse,
        JogWheel::Platter,
        JogTouchState::Released,
        PerformancePad::Pad5,
        PadMode::BeatJump
    }
});

addEntry({
    MidiMessageType::NoteOn,
    DDJ400::Channel::PadA,
    DDJ400::PerformancePad::BeatJumpBase + 5,
    {
        ControllerActionType::PerformancePad,
        Deck::A,
        Button::Unknown,
        Fader::Channel,
        Knob::Trim,
        ButtonState::Released,
        0,
        Encoder::Browse,
        JogWheel::Platter,
        JogTouchState::Released,
        PerformancePad::Pad6,
        PadMode::BeatJump
    }
});

addEntry({
    MidiMessageType::NoteOn,
    DDJ400::Channel::PadA,
    DDJ400::PerformancePad::BeatJumpBase + 6,
    {
        ControllerActionType::PerformancePad,
        Deck::A,
        Button::Unknown,
        Fader::Channel,
        Knob::Trim,
        ButtonState::Released,
        0,
        Encoder::Browse,
        JogWheel::Platter,
        JogTouchState::Released,
        PerformancePad::Pad7,
        PadMode::BeatJump
    }
});

addEntry({
    MidiMessageType::NoteOn,
    DDJ400::Channel::PadA,
    DDJ400::PerformancePad::BeatJumpBase + 7,
    {
        ControllerActionType::PerformancePad,
        Deck::A,
        Button::Unknown,
        Fader::Channel,
        Knob::Trim,
        ButtonState::Released,
        0,
        Encoder::Browse,
        JogWheel::Platter,
        JogTouchState::Released,
        PerformancePad::Pad8,
        PadMode::BeatJump
    }
});

// DECK B
addEntry({
    MidiMessageType::NoteOn,
    DDJ400::Channel::PadB,
    DDJ400::PerformancePad::BeatJumpBase + 0,
    {
        ControllerActionType::PerformancePad,
        Deck::B,
        Button::Unknown,
        Fader::Channel,
        Knob::Trim,
        ButtonState::Released,
        0,
        Encoder::Browse,
        JogWheel::Platter,
        JogTouchState::Released,
        PerformancePad::Pad1,
        PadMode::BeatJump
    }
});

addEntry({
    MidiMessageType::NoteOn,
    DDJ400::Channel::PadB,
    DDJ400::PerformancePad::BeatJumpBase + 1,
    {
        ControllerActionType::PerformancePad,
        Deck::B,
        Button::Unknown,
        Fader::Channel,
        Knob::Trim,
        ButtonState::Released,
        0,
        Encoder::Browse,
        JogWheel::Platter,
        JogTouchState::Released,
        PerformancePad::Pad2,
        PadMode::BeatJump
    }
});

addEntry({
    MidiMessageType::NoteOn,
    DDJ400::Channel::PadB,
    DDJ400::PerformancePad::BeatJumpBase + 2,
    {
        ControllerActionType::PerformancePad,
        Deck::B,
        Button::Unknown,
        Fader::Channel,
        Knob::Trim,
        ButtonState::Released,
        0,
        Encoder::Browse,
        JogWheel::Platter,
        JogTouchState::Released,
        PerformancePad::Pad3,
        PadMode::BeatJump
    }
});

addEntry({
    MidiMessageType::NoteOn,
    DDJ400::Channel::PadB,
    DDJ400::PerformancePad::BeatJumpBase + 3,
    {
        ControllerActionType::PerformancePad,
        Deck::B,
        Button::Unknown,
        Fader::Channel,
        Knob::Trim,
        ButtonState::Released,
        0,
        Encoder::Browse,
        JogWheel::Platter,
        JogTouchState::Released,
        PerformancePad::Pad4,
        PadMode::BeatJump
    }
});

addEntry({
    MidiMessageType::NoteOn,
    DDJ400::Channel::PadB,
    DDJ400::PerformancePad::BeatJumpBase + 4,
    {
        ControllerActionType::PerformancePad,
        Deck::B,
        Button::Unknown,
        Fader::Channel,
        Knob::Trim,
        ButtonState::Released,
        0,
        Encoder::Browse,
        JogWheel::Platter,
        JogTouchState::Released,
        PerformancePad::Pad5,
        PadMode::BeatJump
    }
});

addEntry({
    MidiMessageType::NoteOn,
    DDJ400::Channel::PadB,
    DDJ400::PerformancePad::BeatJumpBase + 5,
    {
        ControllerActionType::PerformancePad,
        Deck::B,
        Button::Unknown,
        Fader::Channel,
        Knob::Trim,
        ButtonState::Released,
        0,
        Encoder::Browse,
        JogWheel::Platter,
        JogTouchState::Released,
        PerformancePad::Pad6,
        PadMode::BeatJump
    }
});

addEntry({
    MidiMessageType::NoteOn,
    DDJ400::Channel::PadB,
    DDJ400::PerformancePad::BeatJumpBase + 6,
    {
        ControllerActionType::PerformancePad,
        Deck::B,
        Button::Unknown,
        Fader::Channel,
        Knob::Trim,
        ButtonState::Released,
        0,
        Encoder::Browse,
        JogWheel::Platter,
        JogTouchState::Released,
        PerformancePad::Pad7,
        PadMode::BeatJump
    }
});

addEntry({
    MidiMessageType::NoteOn,
    DDJ400::Channel::PadB,
    DDJ400::PerformancePad::BeatJumpBase + 7,
    {
        ControllerActionType::PerformancePad,
        Deck::B,
        Button::Unknown,
        Fader::Channel,
        Knob::Trim,
        ButtonState::Released,
        0,
        Encoder::Browse,
        JogWheel::Platter,
        JogTouchState::Released,
        PerformancePad::Pad8,
        PadMode::BeatJump
    }
});

// ============================================================
// PERFORMANCE PADS - SAMPLER
// ============================================================

// DECK A
addEntry({
    MidiMessageType::NoteOn,
    DDJ400::Channel::PadA,
    DDJ400::PerformancePad::SamplerBase + 0,
    {
        ControllerActionType::PerformancePad,
        Deck::A,
        Button::Unknown,
        Fader::Channel,
        Knob::Trim,
        ButtonState::Released,
        0,
        Encoder::Browse,
        JogWheel::Platter,
        JogTouchState::Released,
        PerformancePad::Pad1,
        PadMode::Sampler
    }
});

addEntry({
    MidiMessageType::NoteOn,
    DDJ400::Channel::PadA,
    DDJ400::PerformancePad::SamplerBase + 1,
    {
        ControllerActionType::PerformancePad,
        Deck::A,
        Button::Unknown,
        Fader::Channel,
        Knob::Trim,
        ButtonState::Released,
        0,
        Encoder::Browse,
        JogWheel::Platter,
        JogTouchState::Released,
        PerformancePad::Pad2,
        PadMode::Sampler
    }
});

addEntry({
    MidiMessageType::NoteOn,
    DDJ400::Channel::PadA,
    DDJ400::PerformancePad::SamplerBase + 2,
    {
        ControllerActionType::PerformancePad,
        Deck::A,
        Button::Unknown,
        Fader::Channel,
        Knob::Trim,
        ButtonState::Released,
        0,
        Encoder::Browse,
        JogWheel::Platter,
        JogTouchState::Released,
        PerformancePad::Pad3,
        PadMode::Sampler
    }
});

addEntry({
    MidiMessageType::NoteOn,
    DDJ400::Channel::PadA,
    DDJ400::PerformancePad::SamplerBase + 3,
    {
        ControllerActionType::PerformancePad,
        Deck::A,
        Button::Unknown,
        Fader::Channel,
        Knob::Trim,
        ButtonState::Released,
        0,
        Encoder::Browse,
        JogWheel::Platter,
        JogTouchState::Released,
        PerformancePad::Pad4,
        PadMode::Sampler
    }
});

addEntry({
    MidiMessageType::NoteOn,
    DDJ400::Channel::PadA,
    DDJ400::PerformancePad::SamplerBase + 4,
    {
        ControllerActionType::PerformancePad,
        Deck::A,
        Button::Unknown,
        Fader::Channel,
        Knob::Trim,
        ButtonState::Released,
        0,
        Encoder::Browse,
        JogWheel::Platter,
        JogTouchState::Released,
        PerformancePad::Pad5,
        PadMode::Sampler
    }
});

addEntry({
    MidiMessageType::NoteOn,
    DDJ400::Channel::PadA,
    DDJ400::PerformancePad::SamplerBase + 5,
    {
        ControllerActionType::PerformancePad,
        Deck::A,
        Button::Unknown,
        Fader::Channel,
        Knob::Trim,
        ButtonState::Released,
        0,
        Encoder::Browse,
        JogWheel::Platter,
        JogTouchState::Released,
        PerformancePad::Pad6,
        PadMode::Sampler
    }
});

addEntry({
    MidiMessageType::NoteOn,
    DDJ400::Channel::PadA,
    DDJ400::PerformancePad::SamplerBase + 6,
    {
        ControllerActionType::PerformancePad,
        Deck::A,
        Button::Unknown,
        Fader::Channel,
        Knob::Trim,
        ButtonState::Released,
        0,
        Encoder::Browse,
        JogWheel::Platter,
        JogTouchState::Released,
        PerformancePad::Pad7,
        PadMode::Sampler
    }
});

addEntry({
    MidiMessageType::NoteOn,
    DDJ400::Channel::PadA,
    DDJ400::PerformancePad::SamplerBase + 7,
    {
        ControllerActionType::PerformancePad,
        Deck::A,
        Button::Unknown,
        Fader::Channel,
        Knob::Trim,
        ButtonState::Released,
        0,
        Encoder::Browse,
        JogWheel::Platter,
        JogTouchState::Released,
        PerformancePad::Pad8,
        PadMode::Sampler
    }
});

// DECK B
addEntry({
    MidiMessageType::NoteOn,
    DDJ400::Channel::PadB,
    DDJ400::PerformancePad::SamplerBase + 0,
    {
        ControllerActionType::PerformancePad,
        Deck::B,
        Button::Unknown,
        Fader::Channel,
        Knob::Trim,
        ButtonState::Released,
        0,
        Encoder::Browse,
        JogWheel::Platter,
        JogTouchState::Released,
        PerformancePad::Pad1,
        PadMode::Sampler
    }
});

addEntry({
    MidiMessageType::NoteOn,
    DDJ400::Channel::PadB,
    DDJ400::PerformancePad::SamplerBase + 1,
    {
        ControllerActionType::PerformancePad,
        Deck::B,
        Button::Unknown,
        Fader::Channel,
        Knob::Trim,
        ButtonState::Released,
        0,
        Encoder::Browse,
        JogWheel::Platter,
        JogTouchState::Released,
        PerformancePad::Pad2,
        PadMode::Sampler
    }
});

addEntry({
    MidiMessageType::NoteOn,
    DDJ400::Channel::PadB,
    DDJ400::PerformancePad::SamplerBase + 2,
    {
        ControllerActionType::PerformancePad,
        Deck::B,
        Button::Unknown,
        Fader::Channel,
        Knob::Trim,
        ButtonState::Released,
        0,
        Encoder::Browse,
        JogWheel::Platter,
        JogTouchState::Released,
        PerformancePad::Pad3,
        PadMode::Sampler
    }
});

addEntry({
    MidiMessageType::NoteOn,
    DDJ400::Channel::PadB,
    DDJ400::PerformancePad::SamplerBase + 3,
    {
        ControllerActionType::PerformancePad,
        Deck::B,
        Button::Unknown,
        Fader::Channel,
        Knob::Trim,
        ButtonState::Released,
        0,
        Encoder::Browse,
        JogWheel::Platter,
        JogTouchState::Released,
        PerformancePad::Pad4,
        PadMode::Sampler
    }
});

addEntry({
    MidiMessageType::NoteOn,
    DDJ400::Channel::PadB,
    DDJ400::PerformancePad::SamplerBase + 4,
    {
        ControllerActionType::PerformancePad,
        Deck::B,
        Button::Unknown,
        Fader::Channel,
        Knob::Trim,
        ButtonState::Released,
        0,
        Encoder::Browse,
        JogWheel::Platter,
        JogTouchState::Released,
        PerformancePad::Pad5,
        PadMode::Sampler
    }
});

addEntry({
    MidiMessageType::NoteOn,
    DDJ400::Channel::PadB,
    DDJ400::PerformancePad::SamplerBase + 5,
    {
        ControllerActionType::PerformancePad,
        Deck::B,
        Button::Unknown,
        Fader::Channel,
        Knob::Trim,
        ButtonState::Released,
        0,
        Encoder::Browse,
        JogWheel::Platter,
        JogTouchState::Released,
        PerformancePad::Pad6,
        PadMode::Sampler
    }
});

addEntry({
    MidiMessageType::NoteOn,
    DDJ400::Channel::PadB,
    DDJ400::PerformancePad::SamplerBase + 6,
    {
        ControllerActionType::PerformancePad,
        Deck::B,
        Button::Unknown,
        Fader::Channel,
        Knob::Trim,
        ButtonState::Released,
        0,
        Encoder::Browse,
        JogWheel::Platter,
        JogTouchState::Released,
        PerformancePad::Pad7,
        PadMode::Sampler
    }
});

addEntry({
    MidiMessageType::NoteOn,
    DDJ400::Channel::PadB,
    DDJ400::PerformancePad::SamplerBase + 7,
    {
        ControllerActionType::PerformancePad,
        Deck::B,
        Button::Unknown,
        Fader::Channel,
        Knob::Trim,
        ButtonState::Released,
        0,
        Encoder::Browse,
        JogWheel::Platter,
        JogTouchState::Released,
        PerformancePad::Pad8,
        PadMode::Sampler
    }
});

// ============================================================
// PERFORMANCE PADS - KEYBOARD
// ============================================================

// DECK A
addEntry({
    MidiMessageType::NoteOn,
    DDJ400::Channel::PadA,
    DDJ400::PerformancePad::KeyboardBase + 0,
    {
        ControllerActionType::PerformancePad,
        Deck::A,
        Button::Unknown,
        Fader::Channel,
        Knob::Trim,
        ButtonState::Released,
        0,
        Encoder::Browse,
        JogWheel::Platter,
        JogTouchState::Released,
        PerformancePad::Pad1,
        PadMode::Keyboard
    }
});

addEntry({
    MidiMessageType::NoteOn,
    DDJ400::Channel::PadA,
    DDJ400::PerformancePad::KeyboardBase + 1,
    {
        ControllerActionType::PerformancePad,
        Deck::A,
        Button::Unknown,
        Fader::Channel,
        Knob::Trim,
        ButtonState::Released,
        0,
        Encoder::Browse,
        JogWheel::Platter,
        JogTouchState::Released,
        PerformancePad::Pad2,
        PadMode::Keyboard
    }
});

addEntry({
    MidiMessageType::NoteOn,
    DDJ400::Channel::PadA,
    DDJ400::PerformancePad::KeyboardBase + 2,
    {
        ControllerActionType::PerformancePad,
        Deck::A,
        Button::Unknown,
        Fader::Channel,
        Knob::Trim,
        ButtonState::Released,
        0,
        Encoder::Browse,
        JogWheel::Platter,
        JogTouchState::Released,
        PerformancePad::Pad3,
        PadMode::Keyboard
    }
});

addEntry({
    MidiMessageType::NoteOn,
    DDJ400::Channel::PadA,
    DDJ400::PerformancePad::KeyboardBase + 3,
    {
        ControllerActionType::PerformancePad,
        Deck::A,
        Button::Unknown,
        Fader::Channel,
        Knob::Trim,
        ButtonState::Released,
        0,
        Encoder::Browse,
        JogWheel::Platter,
        JogTouchState::Released,
        PerformancePad::Pad4,
        PadMode::Keyboard
    }
});

addEntry({
    MidiMessageType::NoteOn,
    DDJ400::Channel::PadA,
    DDJ400::PerformancePad::KeyboardBase + 4,
    {
        ControllerActionType::PerformancePad,
        Deck::A,
        Button::Unknown,
        Fader::Channel,
        Knob::Trim,
        ButtonState::Released,
        0,
        Encoder::Browse,
        JogWheel::Platter,
        JogTouchState::Released,
        PerformancePad::Pad5,
        PadMode::Keyboard
    }
});

addEntry({
    MidiMessageType::NoteOn,
    DDJ400::Channel::PadA,
    DDJ400::PerformancePad::KeyboardBase + 5,
    {
        ControllerActionType::PerformancePad,
        Deck::A,
        Button::Unknown,
        Fader::Channel,
        Knob::Trim,
        ButtonState::Released,
        0,
        Encoder::Browse,
        JogWheel::Platter,
        JogTouchState::Released,
        PerformancePad::Pad6,
        PadMode::Keyboard
    }
});

addEntry({
    MidiMessageType::NoteOn,
    DDJ400::Channel::PadA,
    DDJ400::PerformancePad::KeyboardBase + 6,
    {
        ControllerActionType::PerformancePad,
        Deck::A,
        Button::Unknown,
        Fader::Channel,
        Knob::Trim,
        ButtonState::Released,
        0,
        Encoder::Browse,
        JogWheel::Platter,
        JogTouchState::Released,
        PerformancePad::Pad7,
        PadMode::Keyboard
    }
});

addEntry({
    MidiMessageType::NoteOn,
    DDJ400::Channel::PadA,
    DDJ400::PerformancePad::KeyboardBase + 7,
    {
        ControllerActionType::PerformancePad,
        Deck::A,
        Button::Unknown,
        Fader::Channel,
        Knob::Trim,
        ButtonState::Released,
        0,
        Encoder::Browse,
        JogWheel::Platter,
        JogTouchState::Released,
        PerformancePad::Pad8,
        PadMode::Keyboard
    }
});

// DECK B
addEntry({
    MidiMessageType::NoteOn,
    DDJ400::Channel::PadB,
    DDJ400::PerformancePad::KeyboardBase + 0,
    {
        ControllerActionType::PerformancePad,
        Deck::B,
        Button::Unknown,
        Fader::Channel,
        Knob::Trim,
        ButtonState::Released,
        0,
        Encoder::Browse,
        JogWheel::Platter,
        JogTouchState::Released,
        PerformancePad::Pad1,
        PadMode::Keyboard
    }
});

addEntry({
    MidiMessageType::NoteOn,
    DDJ400::Channel::PadB,
    DDJ400::PerformancePad::KeyboardBase + 1,
    {
        ControllerActionType::PerformancePad,
        Deck::B,
        Button::Unknown,
        Fader::Channel,
        Knob::Trim,
        ButtonState::Released,
        0,
        Encoder::Browse,
        JogWheel::Platter,
        JogTouchState::Released,
        PerformancePad::Pad2,
        PadMode::Keyboard
    }
});

addEntry({
    MidiMessageType::NoteOn,
    DDJ400::Channel::PadB,
    DDJ400::PerformancePad::KeyboardBase + 2,
    {
        ControllerActionType::PerformancePad,
        Deck::B,
        Button::Unknown,
        Fader::Channel,
        Knob::Trim,
        ButtonState::Released,
        0,
        Encoder::Browse,
        JogWheel::Platter,
        JogTouchState::Released,
        PerformancePad::Pad3,
        PadMode::Keyboard
    }
});

addEntry({
    MidiMessageType::NoteOn,
    DDJ400::Channel::PadB,
    DDJ400::PerformancePad::KeyboardBase + 3,
    {
        ControllerActionType::PerformancePad,
        Deck::B,
        Button::Unknown,
        Fader::Channel,
        Knob::Trim,
        ButtonState::Released,
        0,
        Encoder::Browse,
        JogWheel::Platter,
        JogTouchState::Released,
        PerformancePad::Pad4,
        PadMode::Keyboard
    }
});

addEntry({
    MidiMessageType::NoteOn,
    DDJ400::Channel::PadB,
    DDJ400::PerformancePad::KeyboardBase + 4,
    {
        ControllerActionType::PerformancePad,
        Deck::B,
        Button::Unknown,
        Fader::Channel,
        Knob::Trim,
        ButtonState::Released,
        0,
        Encoder::Browse,
        JogWheel::Platter,
        JogTouchState::Released,
        PerformancePad::Pad5,
        PadMode::Keyboard
    }
});

addEntry({
    MidiMessageType::NoteOn,
    DDJ400::Channel::PadB,
    DDJ400::PerformancePad::KeyboardBase + 5,
    {
        ControllerActionType::PerformancePad,
        Deck::B,
        Button::Unknown,
        Fader::Channel,
        Knob::Trim,
        ButtonState::Released,
        0,
        Encoder::Browse,
        JogWheel::Platter,
        JogTouchState::Released,
        PerformancePad::Pad6,
        PadMode::Keyboard
    }
});

addEntry({
    MidiMessageType::NoteOn,
    DDJ400::Channel::PadB,
    DDJ400::PerformancePad::KeyboardBase + 6,
    {
        ControllerActionType::PerformancePad,
        Deck::B,
        Button::Unknown,
        Fader::Channel,
        Knob::Trim,
        ButtonState::Released,
        0,
        Encoder::Browse,
        JogWheel::Platter,
        JogTouchState::Released,
        PerformancePad::Pad7,
        PadMode::Keyboard
    }
});

addEntry({
    MidiMessageType::NoteOn,
    DDJ400::Channel::PadB,
    DDJ400::PerformancePad::KeyboardBase + 7,
    {
        ControllerActionType::PerformancePad,
        Deck::B,
        Button::Unknown,
        Fader::Channel,
        Knob::Trim,
        ButtonState::Released,
        0,
        Encoder::Browse,
        JogWheel::Platter,
        JogTouchState::Released,
        PerformancePad::Pad8,
        PadMode::Keyboard
    }
});

    // ============================================================
// PERFORMANCE PADS - BEAT LOOP
// ============================================================

// DECK A
addEntry({
    MidiMessageType::NoteOn,
    DDJ400::Channel::PadA,
    DDJ400::PerformancePad::BeatLoopBase + 0,
    {
        ControllerActionType::PerformancePad,
        Deck::A,
        Button::Unknown,
        Fader::Channel,
        Knob::Trim,
        ButtonState::Released,
        0,
        Encoder::Browse,
        JogWheel::Platter,
        JogTouchState::Released,
        PerformancePad::Pad1,
        PadMode::BeatLoop
    }
});

addEntry({
    MidiMessageType::NoteOn,
    DDJ400::Channel::PadA,
    DDJ400::PerformancePad::BeatLoopBase + 1,
    {
        ControllerActionType::PerformancePad,
        Deck::A,
        Button::Unknown,
        Fader::Channel,
        Knob::Trim,
        ButtonState::Released,
        0,
        Encoder::Browse,
        JogWheel::Platter,
        JogTouchState::Released,
        PerformancePad::Pad2,
        PadMode::BeatLoop
    }
});

addEntry({
    MidiMessageType::NoteOn,
    DDJ400::Channel::PadA,
    DDJ400::PerformancePad::BeatLoopBase + 2,
    {
        ControllerActionType::PerformancePad,
        Deck::A,
        Button::Unknown,
        Fader::Channel,
        Knob::Trim,
        ButtonState::Released,
        0,
        Encoder::Browse,
        JogWheel::Platter,
        JogTouchState::Released,
        PerformancePad::Pad3,
        PadMode::BeatLoop
    }
});

addEntry({
    MidiMessageType::NoteOn,
    DDJ400::Channel::PadA,
    DDJ400::PerformancePad::BeatLoopBase + 3,
    {
        ControllerActionType::PerformancePad,
        Deck::A,
        Button::Unknown,
        Fader::Channel,
        Knob::Trim,
        ButtonState::Released,
        0,
        Encoder::Browse,
        JogWheel::Platter,
        JogTouchState::Released,
        PerformancePad::Pad4,
        PadMode::BeatLoop
    }
});

addEntry({
    MidiMessageType::NoteOn,
    DDJ400::Channel::PadA,
    DDJ400::PerformancePad::BeatLoopBase + 4,
    {
        ControllerActionType::PerformancePad,
        Deck::A,
        Button::Unknown,
        Fader::Channel,
        Knob::Trim,
        ButtonState::Released,
        0,
        Encoder::Browse,
        JogWheel::Platter,
        JogTouchState::Released,
        PerformancePad::Pad5,
        PadMode::BeatLoop
    }
});

addEntry({
    MidiMessageType::NoteOn,
    DDJ400::Channel::PadA,
    DDJ400::PerformancePad::BeatLoopBase + 5,
    {
        ControllerActionType::PerformancePad,
        Deck::A,
        Button::Unknown,
        Fader::Channel,
        Knob::Trim,
        ButtonState::Released,
        0,
        Encoder::Browse,
        JogWheel::Platter,
        JogTouchState::Released,
        PerformancePad::Pad6,
        PadMode::BeatLoop
    }
});

addEntry({
    MidiMessageType::NoteOn,
    DDJ400::Channel::PadA,
    DDJ400::PerformancePad::BeatLoopBase + 6,
    {
        ControllerActionType::PerformancePad,
        Deck::A,
        Button::Unknown,
        Fader::Channel,
        Knob::Trim,
        ButtonState::Released,
        0,
        Encoder::Browse,
        JogWheel::Platter,
        JogTouchState::Released,
        PerformancePad::Pad7,
        PadMode::BeatLoop
    }
});

addEntry({
    MidiMessageType::NoteOn,
    DDJ400::Channel::PadA,
    DDJ400::PerformancePad::BeatLoopBase + 7,
    {
        ControllerActionType::PerformancePad,
        Deck::A,
        Button::Unknown,
        Fader::Channel,
        Knob::Trim,
        ButtonState::Released,
        0,
        Encoder::Browse,
        JogWheel::Platter,
        JogTouchState::Released,
        PerformancePad::Pad8,
        PadMode::BeatLoop
    }
});

// DECK B
addEntry({
    MidiMessageType::NoteOn,
    DDJ400::Channel::PadB,
    DDJ400::PerformancePad::BeatLoopBase + 0,
    {
        ControllerActionType::PerformancePad,
        Deck::B,
        Button::Unknown,
        Fader::Channel,
        Knob::Trim,
        ButtonState::Released,
        0,
        Encoder::Browse,
        JogWheel::Platter,
        JogTouchState::Released,
        PerformancePad::Pad1,
        PadMode::BeatLoop
    }
});

addEntry({
    MidiMessageType::NoteOn,
    DDJ400::Channel::PadB,
    DDJ400::PerformancePad::BeatLoopBase + 1,
    {
        ControllerActionType::PerformancePad,
        Deck::B,
        Button::Unknown,
        Fader::Channel,
        Knob::Trim,
        ButtonState::Released,
        0,
        Encoder::Browse,
        JogWheel::Platter,
        JogTouchState::Released,
        PerformancePad::Pad2,
        PadMode::BeatLoop
    }
});

addEntry({
    MidiMessageType::NoteOn,
    DDJ400::Channel::PadB,
    DDJ400::PerformancePad::BeatLoopBase + 2,
    {
        ControllerActionType::PerformancePad,
        Deck::B,
        Button::Unknown,
        Fader::Channel,
        Knob::Trim,
        ButtonState::Released,
        0,
        Encoder::Browse,
        JogWheel::Platter,
        JogTouchState::Released,
        PerformancePad::Pad3,
        PadMode::BeatLoop
    }
});

addEntry({
    MidiMessageType::NoteOn,
    DDJ400::Channel::PadB,
    DDJ400::PerformancePad::BeatLoopBase + 3,
    {
        ControllerActionType::PerformancePad,
        Deck::B,
        Button::Unknown,
        Fader::Channel,
        Knob::Trim,
        ButtonState::Released,
        0,
        Encoder::Browse,
        JogWheel::Platter,
        JogTouchState::Released,
        PerformancePad::Pad4,
        PadMode::BeatLoop
    }
});

addEntry({
    MidiMessageType::NoteOn,
    DDJ400::Channel::PadB,
    DDJ400::PerformancePad::BeatLoopBase + 4,
    {
        ControllerActionType::PerformancePad,
        Deck::B,
        Button::Unknown,
        Fader::Channel,
        Knob::Trim,
        ButtonState::Released,
        0,
        Encoder::Browse,
        JogWheel::Platter,
        JogTouchState::Released,
        PerformancePad::Pad5,
        PadMode::BeatLoop
    }
});

addEntry({
    MidiMessageType::NoteOn,
    DDJ400::Channel::PadB,
    DDJ400::PerformancePad::BeatLoopBase + 5,
    {
        ControllerActionType::PerformancePad,
        Deck::B,
        Button::Unknown,
        Fader::Channel,
        Knob::Trim,
        ButtonState::Released,
        0,
        Encoder::Browse,
        JogWheel::Platter,
        JogTouchState::Released,
        PerformancePad::Pad6,
        PadMode::BeatLoop
    }
});

addEntry({
    MidiMessageType::NoteOn,
    DDJ400::Channel::PadB,
    DDJ400::PerformancePad::BeatLoopBase + 6,
    {
        ControllerActionType::PerformancePad,
        Deck::B,
        Button::Unknown,
        Fader::Channel,
        Knob::Trim,
        ButtonState::Released,
        0,
        Encoder::Browse,
        JogWheel::Platter,
        JogTouchState::Released,
        PerformancePad::Pad7,
        PadMode::BeatLoop
    }
});

addEntry({
    MidiMessageType::NoteOn,
    DDJ400::Channel::PadB,
    DDJ400::PerformancePad::BeatLoopBase + 7,
    {
        ControllerActionType::PerformancePad,
        Deck::B,
        Button::Unknown,
        Fader::Channel,
        Knob::Trim,
        ButtonState::Released,
        0,
        Encoder::Browse,
        JogWheel::Platter,
        JogTouchState::Released,
        PerformancePad::Pad8,
        PadMode::BeatLoop
    }
});

    // ============================================================
    // MIXER - CHANNEL FADERS
    // ============================================================

    // Deck A - CHANNEL FADER
    // MIDI 14-bit: MSB CC 19 / LSB CC 51
    // El perfil identifica el control por el CC base (MSB = 19).
    addEntry({
        MidiMessageType::ControlChange,
        DDJ400::Channel::DeckA,
        DDJ400::Mixer::ChannelFader,
        {
            ControllerActionType::Fader,
            Deck::A,
            Button::Unknown,
            Fader::Channel,
            Knob::Trim,
            ButtonState::Released,
            0
        }
    });

    // Deck B - CHANNEL FADER
    // MIDI 14-bit: MSB CC 19 / LSB CC 51
    addEntry({
        MidiMessageType::ControlChange,
        DDJ400::Channel::DeckB,
        DDJ400::Mixer::ChannelFader,
        {
            ControllerActionType::Fader,
            Deck::B,
            Button::Unknown,
            Fader::Channel,
            Knob::Trim,
            ButtonState::Released,
            0
        }
    });

    // ============================================================
    // JOG WHEELS - NORMAL ROTATION
    // ============================================================

    // JOG ROTATION - DECK A
    addEntry({
        MidiMessageType::ControlChange,
        DDJ400::Channel::DeckA,
        DDJ400::Jog::Rotation,
        {
            ControllerActionType::JogWheel,
            Deck::A,
            Button::Unknown,
            Fader::Channel,
            Knob::Trim,
            ButtonState::Released,
            0,
            Encoder::Browse,
            JogWheel::Platter,
            JogTouchState::Released
        }
    });

    // JOG ROTATION - DECK B
    addEntry({
        MidiMessageType::ControlChange,
        DDJ400::Channel::DeckB,
        DDJ400::Jog::Rotation,
        {
            ControllerActionType::JogWheel,
            Deck::B,
            Button::Unknown,
            Fader::Channel,
            Knob::Trim,
            ButtonState::Released,
            0,
            Encoder::Browse,
            JogWheel::Platter,
            JogTouchState::Released
        }
    });

    // ============================================================
    // JOG WHEELS - SCRATCH ROTATION
    // ============================================================

    // SCRATCH ROTATION - DECK A
    addEntry({
        MidiMessageType::ControlChange,
        DDJ400::Channel::DeckA,
        DDJ400::Jog::ScratchRotation,
        {
            ControllerActionType::JogWheel,
            Deck::A,
            Button::Unknown,
            Fader::Channel,
            Knob::Trim,
            ButtonState::Released,
            0,
            Encoder::Browse,
            JogWheel::Scratch,
            JogTouchState::Released
        }
    });

    // SCRATCH ROTATION - DECK B
    addEntry({
        MidiMessageType::ControlChange,
        DDJ400::Channel::DeckB,
        DDJ400::Jog::ScratchRotation,
        {
            ControllerActionType::JogWheel,
            Deck::B,
            Button::Unknown,
            Fader::Channel,
            Knob::Trim,
            ButtonState::Released,
            0,
            Encoder::Browse,
            JogWheel::Scratch,
            JogTouchState::Released
        }
    });

    // ============================================================
    // JOG WHEELS - SEARCH ROTATION
    // SHIFT + JOG
    // ============================================================

    // SEARCH ROTATION - DECK A
    addEntry({
        MidiMessageType::ControlChange,
        DDJ400::Channel::DeckA,
        DDJ400::Jog::SearchRotation,
        {
            ControllerActionType::JogWheel,
            Deck::A,
            Button::Unknown,
            Fader::Channel,
            Knob::Trim,
            ButtonState::Released,
            0,
            Encoder::Browse,
            JogWheel::Search,
            JogTouchState::Released
        }
    });

    // SEARCH ROTATION - DECK B
    addEntry({
        MidiMessageType::ControlChange,
        DDJ400::Channel::DeckB,
        DDJ400::Jog::SearchRotation,
        {
            ControllerActionType::JogWheel,
            Deck::B,
            Button::Unknown,
            Fader::Channel,
            Knob::Trim,
            ButtonState::Released,
            0,
            Encoder::Browse,
            JogWheel::Search,
            JogTouchState::Released
        }
    });

    // ============================================================
    // JOG WHEELS - TOUCH
    // ============================================================

    // TOUCH - DECK A
    addEntry({
        MidiMessageType::NoteOn,
        DDJ400::Channel::DeckA,
        DDJ400::Jog::Touch,
        {
            ControllerActionType::JogTouch,
            Deck::A,
            Button::Unknown,
            Fader::Channel,
            Knob::Trim,
            ButtonState::Released,
            0,
            Encoder::Browse,
            JogWheel::Platter,
            JogTouchState::Released
        }
    });

    // TOUCH - DECK B
    addEntry({
        MidiMessageType::NoteOn,
        DDJ400::Channel::DeckB,
        DDJ400::Jog::Touch,
        {
            ControllerActionType::JogTouch,
            Deck::B,
            Button::Unknown,
            Fader::Channel,
            Knob::Trim,
            ButtonState::Released,
            0,
            Encoder::Browse,
            JogWheel::Platter,
            JogTouchState::Released
        }
    });
}

} // namespace OpenDJ