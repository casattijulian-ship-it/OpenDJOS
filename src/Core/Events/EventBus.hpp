#pragma once

#include "Event.hpp"
#include "EventListener.hpp"
#include "EventType.hpp"

#include "Core/Services/IService.hpp"

#include <unordered_map>
#include <vector>

namespace OpenDJ
{

class EventBus final : public IService
{
public:

    EventBus() = default;

    ~EventBus() override = default;

    bool initialize() override;

    void shutdown() override;

    void subscribe(EventType type, EventListener listener);

    void publish(const Event& event);

private:

    std::unordered_map<EventType, std::vector<EventListener>> m_listeners;
};

}