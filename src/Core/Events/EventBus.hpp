#pragma once

#include "Event.hpp"
#include "Core/Services/IService.hpp"

namespace OpenDJ
{

class EventBus final : public IService
{
public:
    EventBus() = default;
    ~EventBus() override = default;

    bool initialize() override;
    void shutdown() override;

    void publish(const Event& event);
};

} // namespace OpenDJ