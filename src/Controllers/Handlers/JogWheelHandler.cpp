#include "JogWheelHandler.hpp"

#include "Core/Logging/Logger.hpp"

#include <string>

namespace OpenDJ
{

JogWheelAction JogWheelHandler::handle(
    const JogWheelEvent& event)
{
    JogWheelAction action;

    action.deck = event.deck();
    action.jogWheel = event.jogWheel();
    action.delta = event.delta();

    bool touched = false;

    switch (event.deck())
    {
        case Deck::A:
            touched = m_deckATouched;
            break;

        case Deck::B:
            touched = m_deckBTouched;
            break;

        case Deck::None:
        case Deck::Master:
            return action;
    }

    switch (event.jogWheel())
    {
        case JogWheel::Platter:

            action.type =
                JogWheelActionType::Platter;

            break;

        case JogWheel::Scratch:

            if (!touched)
            {
                return JogWheelAction{};
            }

            action.type =
                JogWheelActionType::Scratch;

            break;

        case JogWheel::Search:

            action.type =
                JogWheelActionType::Search;

            break;
    }

    return action;
}

void JogWheelHandler::handleTouch(
    const JogTouchEvent& event)
{
    const bool touched =
        event.state() == JogTouchState::Touched;

    switch (event.deck())
    {
        case Deck::A:

            m_deckATouched = touched;

            Logger::info(
                "JogWheelHandler -> Deck A Touch -> " +
                std::string(
                    touched
                        ? "TOUCHED"
                        : "RELEASED"));

            break;

        case Deck::B:

            m_deckBTouched = touched;

            Logger::info(
                "JogWheelHandler -> Deck B Touch -> " +
                std::string(
                    touched
                        ? "TOUCHED"
                        : "RELEASED"));

            break;

        case Deck::None:
        case Deck::Master:
            break;
    }
}

} // namespace OpenDJ