#include "ControllerMapper.hpp"

#include "ButtonEvent.hpp"
#include "FaderEvent.hpp"

namespace OpenDJ
{

ControllerMapper::ControllerMapper(const ControllerProfile& profile)
    : m_profile(profile)
{
}

std::unique_ptr<ControllerEvent> ControllerMapper::map(const MidiEvent& event) const
{
    auto entry = m_profile.find(event);

    if (!entry)
    {
        return nullptr;
    }

    switch (entry->action.type)
    {
        case ControllerActionType::Button:
        {
            return std::make_unique<ButtonEvent>(
                entry->action.deck,
                entry->action.button,
                entry->action.buttonState);
        }

        case ControllerActionType::Fader:
        {
            return std::make_unique<FaderEvent>(
                entry->action.deck,
                entry->action.fader,
                entry->action.value);
        }

        default:
        {
            return nullptr;
        }
    }
}

} // namespace OpenDJ