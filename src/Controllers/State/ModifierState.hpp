#pragma once

#include "../Types/Deck.hpp"

namespace OpenDJ
{

class ModifierState
{
public:

    void setShift(
        Deck deck,
        bool pressed);

    bool isShiftPressed(
        Deck deck) const;

private:

    bool m_shiftDeckA = false;

    bool m_shiftDeckB = false;
};

} // namespace OpenDJ