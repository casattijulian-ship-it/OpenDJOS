#pragma once

#include "MidiEvent.hpp"

#include <cstdint>
#include <optional>
#include <unordered_map>

namespace OpenDJ
{

struct Midi14BitEvent
{
    std::uint8_t channel = 0;
    std::uint8_t number = 0;
    std::uint16_t value = 0;
};

class Midi14BitProcessor
{
public:

    Midi14BitProcessor() = default;

    std::optional<Midi14BitEvent> process(
        const MidiEvent& event);

private:

    struct ControlState
    {
        std::uint8_t msb = 0;
        std::uint8_t lsb = 0;

        bool hasMsb = false;
        bool hasLsb = false;
    };

    static std::uint16_t makeKey(
        std::uint8_t channel,
        std::uint8_t number);

    std::unordered_map<std::uint16_t, ControlState> m_states;
};

} // namespace OpenDJ