#include "ServiceManager.hpp"

#include "Controllers/Mapping/PerformancePadEvent.hpp"
#include "Controllers/Mapping/ButtonEvent.hpp"
#include "Controllers/Mapping/JogWheelEvent.hpp"
#include "Controllers/Mapping/JogTouchEvent.hpp"

namespace OpenDJ
{

ServiceManager::ServiceManager()
    : m_midiService(m_eventBus)
{
}

bool ServiceManager::initialize()
{
    // ========================================================
    // EVENT BUS
    // ========================================================

    if (!m_eventBus.initialize())
    {
        return false;
    }

    // ========================================================
    // PERFORMANCE PAD HANDLER
    // ========================================================

    m_eventBus.subscribe(
        EventType::PerformancePad,
        [this](const Event& event)
        {
            const auto* performancePadEvent =
                dynamic_cast<const PerformancePadEvent*>(&event);

            if (!performancePadEvent)
            {
                return;
            }

            const PerformancePadAction action =
                m_performancePadHandler.handle(
                    *performancePadEvent);

            (void)action;
        });

    // ========================================================
    // BUTTON HANDLER
    // ========================================================

    m_eventBus.subscribe(
        EventType::Button,
        [this](const Event& event)
        {
            const auto* buttonEvent =
                dynamic_cast<const ButtonEvent*>(&event);

            if (!buttonEvent)
            {
                return;
            }

            const ButtonAction action =
                m_buttonHandler.handle(*buttonEvent);

            m_buttonActionExecutor.execute(action);
        });

    // ========================================================
    // JOG WHEEL HANDLER
    // ========================================================

    m_eventBus.subscribe(
        EventType::JogWheel,
        [this](const Event& event)
        {
            const auto* jogWheelEvent =
                dynamic_cast<const JogWheelEvent*>(&event);

            if (!jogWheelEvent)
            {
                return;
            }

            const JogWheelAction action =
                m_jogWheelHandler.handle(*jogWheelEvent);

            m_jogWheelActionExecutor.execute(action);
        });

    // ========================================================
    // JOG TOUCH HANDLER
    // ========================================================

    m_eventBus.subscribe(
        EventType::JogTouch,
        [this](const Event& event)
        {
            const auto* jogTouchEvent =
                dynamic_cast<const JogTouchEvent*>(&event);

            if (!jogTouchEvent)
            {
                return;
            }

            m_jogWheelHandler.handleTouch(
                *jogTouchEvent);
        });

    // ========================================================
    // MIDI SERVICE
    // ========================================================

    if (!m_midiService.initialize())
    {
        m_eventBus.shutdown();

        return false;
    }

    return true;
}

void ServiceManager::update()
{
    m_midiService.update();
}

void ServiceManager::shutdown()
{
    m_midiService.shutdown();

    m_eventBus.shutdown();
}

EventBus& ServiceManager::eventBus()
{
    return m_eventBus;
}

} // namespace OpenDJ