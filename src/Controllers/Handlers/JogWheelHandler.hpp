#pragma once

#include "../Mapping/JogWheelEvent.hpp"
#include "../Mapping/JogTouchEvent.hpp"

#include "JogWheelAction.hpp"

namespace OpenDJ
{

class JogWheelHandler
{
public:

    JogWheelAction handle(
        const JogWheelEvent& event);

    void handleTouch(
        const JogTouchEvent& event);

private:

    bool m_deckATouched = false;

    bool m_deckBTouched = false;
};

} // namespace OpenDJ