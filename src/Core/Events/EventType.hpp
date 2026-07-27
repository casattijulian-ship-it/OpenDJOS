#pragma once

namespace OpenDJ
{

enum class EventType
{
    Unknown = 0,

    // Controller
    ControllerConnected,
    ControllerDisconnected,
    ButtonPressed,
    ButtonReleased,
    KnobMoved,
    FaderMoved,

    // Playback
    PlaybackStarted,
    PlaybackStopped,
    TrackLoaded,

    // Library
    LibraryUpdated
};

}