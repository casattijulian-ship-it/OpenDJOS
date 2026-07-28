#include "DDJ400Profile.hpp"

#include "DDJ400Definitions.hpp"

#include "../Types/Button.hpp"
#include "../Types/ButtonState.hpp"
#include "../Types/Deck.hpp"
#include "../Types/Fader.hpp"

namespace OpenDJ
{

DDJ400Profile::DDJ400Profile()
{
    // ============================================================
    // TRANSPORT
    // ============================================================

    // ------------------------------------------------------------
    // Deck A - PLAY
    // ------------------------------------------------------------

    addEntry({
        MidiMessageType::NoteOn,
        DDJ400::Channel::DeckA,
        DDJ400::Transport::Play,
        {
            ControllerActionType::Button,
            Deck::A,
            Button::Play,
            Fader::Channel,
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
            ButtonState::Released,
            0
        }
    });

    // ------------------------------------------------------------
    // Deck B - PLAY
    // ------------------------------------------------------------

    addEntry({
        MidiMessageType::NoteOn,
        DDJ400::Channel::DeckB,
        DDJ400::Transport::Play,
        {
            ControllerActionType::Button,
            Deck::B,
            Button::Play,
            Fader::Channel,
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
            ButtonState::Released,
            0
        }
    });
}

} // namespace OpenDJ