#include "JogWheelActionExecutor.hpp"

#include "Core/Logging/Logger.hpp"

#include <string>

namespace OpenDJ
{

void JogWheelActionExecutor::execute(
    const JogWheelAction& action)
{
    if (action.type == JogWheelActionType::None)
    {
        return;
    }

    std::string deck = "Unknown";

    if (action.deck == Deck::A)
    {
        deck = "A";
    }
    else if (action.deck == Deck::B)
    {
        deck = "B";
    }

    std::string jogWheel = "UNKNOWN";

    switch (action.jogWheel)
    {
        case JogWheel::Platter:
            jogWheel = "PLATTER";
            break;

        case JogWheel::Scratch:
            jogWheel = "SCRATCH";
            break;

        case JogWheel::Search:
            jogWheel = "SEARCH";
            break;
    }

    std::string actionName = "UNKNOWN";

    switch (action.type)
    {
        case JogWheelActionType::Platter:
            actionName = "PLATTER";
            break;

        case JogWheelActionType::Scratch:
            actionName = "SCRATCH";
            break;

        case JogWheelActionType::Search:
            actionName = "SEARCH";
            break;

        case JogWheelActionType::None:
            return;
    }

    Logger::info(
        "JogWheelActionExecutor -> Deck " +
        deck +
        " | " +
        jogWheel +
        " | " +
        actionName +
        " | DELTA " +
        std::to_string(action.delta));
}

} // namespace OpenDJ
