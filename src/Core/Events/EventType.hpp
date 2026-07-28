#pragma once

namespace OpenDJ
{

enum class EventType
{
    Unknown = 0,

    // Controller
    ControllerConnected,
    ControllerDisconnected,

    Button,
    Fader,
    Knob,
    Encoder,
    JogWheel,

    // Playback
    PlaybackStarted,
    PlaybackStopped,
    TrackLoaded,

    // Library
    LibraryUpdated
};

}