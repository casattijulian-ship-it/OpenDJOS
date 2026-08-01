#pragma once

#include "MidiEvent.hpp"
#include "Midi14BitProcessor.hpp"

#include <cstdint>
#include <unordered_set>

namespace OpenDJ
{

class MidiCapture
{
public:

    MidiCapture() = default;

    void process(const MidiEvent& event);

    void reset();

private:

    static std::uint32_t makeKey(
        MidiMessageType type,
        std::uint8_t channel,
        std::uint8_t number);

    std::unordered_set<std::uint32_t> m_seenControls;

    Midi14BitProcessor m_14BitProcessor;
};

} // namespace OpenDJ