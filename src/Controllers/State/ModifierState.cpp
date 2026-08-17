#include "ModifierState.hpp"

namespace OpenDJ
{

void ModifierState::setShift(
    Deck deck,
    bool pressed)
{
    switch (deck)
    {
        case Deck::A:
            m_shiftDeckA = pressed;
            break;

        case Deck::B:
            m_shiftDeckB = pressed;
            break;

        case Deck::None:
        case Deck::Master:
            break;
    }
}

bool ModifierState::isShiftPressed(
    Deck deck) const
{
    switch (deck)
    {
        case Deck::A:
            return m_shiftDeckA;

        case Deck::B:
            return m_shiftDeckB;

        case Deck::None:
        case Deck::Master:
            return false;
    }

    return false;
}

} // namespace OpenDJ