#pragma once

#include <cstdint>

namespace OpenDJ::DDJ400
{

// ============================================================
// MIDI Channels
// ============================================================

namespace Channel
{
    constexpr std::uint8_t DeckA = 0;
    constexpr std::uint8_t DeckB = 1;
    constexpr std::uint8_t Effect = 4;
    constexpr std::uint8_t Browser = 6;
    constexpr std::uint8_t PadA = 7;
    constexpr std::uint8_t PadB = 9;
}

// ============================================================
// Deck Transport
// ============================================================

namespace Transport
{
    constexpr std::uint8_t Play = 11;
    constexpr std::uint8_t Cue = 12;
    constexpr std::uint8_t BeatSync = 88;
    constexpr std::uint8_t Shift = 63;

    constexpr std::uint8_t LoopIn = 16;
    constexpr std::uint8_t LoopOut = 17;
    constexpr std::uint8_t ReloopExit = 77;

    constexpr std::uint8_t CueLoopCallLeft = 54;
    constexpr std::uint8_t CueLoopCallRight = 83;
}

// ============================================================
// Jog Wheel
// ============================================================

namespace Jog
{
    constexpr std::uint8_t Touch = 54;
    constexpr std::uint8_t Rotation = 33;
}

// ============================================================
// Tempo
// ============================================================

namespace Tempo
{
    constexpr std::uint8_t Slider = 0;
}

// ============================================================
// Mixer
// ============================================================

namespace Mixer
{
    constexpr std::uint8_t Crossfader = 31;

    constexpr std::uint8_t ChannelFader = 19;

    constexpr std::uint8_t Trim = 4;

    constexpr std::uint8_t EqHigh = 7;
    constexpr std::uint8_t EqMid = 11;
    constexpr std::uint8_t EqLow = 15;

    constexpr std::uint8_t FilterCh1 = 23;
    constexpr std::uint8_t FilterCh2 = 24;
}

// ============================================================
// Browser
// ============================================================

namespace Browser
{
    constexpr std::uint8_t Rotary = 64;

    constexpr std::uint8_t Push = 65;

    constexpr std::uint8_t LoadLeft = 70;
    constexpr std::uint8_t LoadRight = 71;
}

} // namespace OpenDJ::DDJ400