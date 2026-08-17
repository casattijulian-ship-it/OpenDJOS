#include "MidiService.hpp"

#include "Core/Logging/Logger.hpp"

#include "Controllers/Profiles/DDJ400Profile.hpp"

#include "Controllers/Mapping/ButtonEvent.hpp"
#include "Controllers/Mapping/FaderEvent.hpp"
#include "Controllers/Mapping/KnobEvent.hpp"
#include "Controllers/Mapping/EncoderEvent.hpp"
#include "Controllers/Mapping/JogWheelEvent.hpp"
#include "Controllers/Mapping/JogTouchEvent.hpp"

#include <exception>
#include <memory>
#include <string>

namespace OpenDJ
{

MidiService::MidiService(EventBus& eventBus)
    : m_eventBus(eventBus)
{
}

bool MidiService::initialize()
{
    try
    {
        Logger::info("Initializing MIDI service...");

        const auto devices = m_deviceManager.enumerate();

        Logger::info(
            "Detected " +
            std::to_string(devices.size()) +
            " MIDI device(s).");

        for (const auto& device : devices)
        {
            Logger::info(" - " + device.name());

            if (device.name().find("DDJ-400") != std::string::npos)
            {
                Logger::info("DDJ-400 detected.");

                m_profile =
                    std::make_unique<DDJ400Profile>();

                m_processor =
                    std::make_unique<MidiProcessor>(*m_profile);

                m_input =
                    std::make_unique<MidiInput>(device);

                if (m_input->open())
                {
                    Logger::info("Connected to DDJ-400.");
                }
                else
                {
                    Logger::warning(
                        "Failed to open DDJ-400.");

                    m_input.reset();
                    m_processor.reset();
                    m_profile.reset();
                }

                break;
            }
        }

        if (!m_input)
        {
            Logger::warning(
                "No DDJ-400 controller found.");
        }

        Logger::info("MidiService initialized.");

        return true;
    }
    catch (const std::exception& e)
    {
        Logger::error(e.what());

        return false;
    }
}

void MidiService::update()
{
    if (!m_input || !m_processor)
    {
        return;
    }

    MidiEvent midiEvent;

    while (m_input->poll(midiEvent))
    {
        // ========================================================
        // MIDI CAPTURE
        // ========================================================

        m_capture.process(midiEvent);

        // ========================================================
        // RAW MIDI DEBUG
        // ========================================================

        Logger::debug(
            "RAW MIDI -> type=" +
            std::to_string(
                static_cast<int>(midiEvent.type)) +
            " channel=" +
            std::to_string(
                static_cast<int>(midiEvent.channel)) +
            " number=" +
            std::to_string(
                static_cast<int>(midiEvent.number)) +
            " value=" +
            std::to_string(
                static_cast<int>(midiEvent.value)));

        // ========================================================
        // MIDI 14-BIT PROCESSOR
        // ========================================================

        auto event14Bit =
            m_14BitProcessor.process(midiEvent);

        if (event14Bit)
        {
            Logger::debug(
                "MIDI 14-BIT -> channel=" +
                std::to_string(
                    static_cast<int>(
                        event14Bit->channel)) +
                " number=" +
                std::to_string(
                    static_cast<int>(
                        event14Bit->number)) +
                " value=" +
                std::to_string(
                    event14Bit->value));

            auto controllerEvent14Bit =
                m_processor->process(*event14Bit);

            if (controllerEvent14Bit)
            {
                // =================================================
                // EVENT BUS
                // =================================================

                m_eventBus.publish(
                    *controllerEvent14Bit);

                // =================================================
                // FADER EVENT
                // =================================================

                if (
                    controllerEvent14Bit->type() ==
                    EventType::Fader)
                {
                    const auto* faderEvent =
                        dynamic_cast<const FaderEvent*>(
                            controllerEvent14Bit.get());

                    if (faderEvent)
                    {
                        switch (faderEvent->fader())
                        {
                            case Fader::Channel:
                            {
                                std::string deck =
                                    "Unknown";

                                if (
                                    faderEvent->deck() ==
                                    Deck::A)
                                {
                                    deck = "A";
                                }
                                else if (
                                    faderEvent->deck() ==
                                    Deck::B)
                                {
                                    deck = "B";
                                }

                                Logger::info(
                                    "CHANNEL FADER Deck " +
                                    deck +
                                    " -> " +
                                    std::to_string(
                                        faderEvent->value()));

                                break;
                            }

                            case Fader::Crossfader:
                            {
                                Logger::info(
                                    "CROSSFADER -> " +
                                    std::to_string(
                                        faderEvent->value()));

                                break;
                            }

                            case Fader::Tempo:
                            {
                                std::string deck =
                                    "Unknown";

                                if (
                                    faderEvent->deck() ==
                                    Deck::A)
                                {
                                    deck = "A";
                                }
                                else if (
                                    faderEvent->deck() ==
                                    Deck::B)
                                {
                                    deck = "B";
                                }

                                Logger::info(
                                    "TEMPO FADER Deck " +
                                    deck +
                                    " -> " +
                                    std::to_string(
                                        faderEvent->value()));

                                break;
                            }
                        }
                    }
                }

                // =================================================
                // KNOB EVENT
                // =================================================

                else if (
                    controllerEvent14Bit->type() ==
                    EventType::Knob)
                {
                    const auto* knobEvent =
                        dynamic_cast<const KnobEvent*>(
                            controllerEvent14Bit.get());

                    if (knobEvent)
                    {
                        std::string deck =
                            "Unknown";

                        if (
                            knobEvent->deck() ==
                            Deck::A)
                        {
                            deck = "A";
                        }
                        else if (
                            knobEvent->deck() ==
                            Deck::B)
                        {
                            deck = "B";
                        }

                        std::string knob =
                            "UNKNOWN KNOB";

                        switch (knobEvent->knob())
                        {
                            case Knob::Trim:
                                knob = "TRIM";
                                break;

                            case Knob::EqHigh:
                                knob = "EQ HIGH";
                                break;

                            case Knob::EqMid:
                                knob = "EQ MID";
                                break;

                            case Knob::EqLow:
                                knob = "EQ LOW";
                                break;

                            case Knob::Filter:
                                knob = "FILTER";
                                break;
                        }

                        Logger::info(
                            knob +
                            " Deck " +
                            deck +
                            " -> " +
                            std::to_string(
                                knobEvent->value()));
                    }
                }
            }
        }

        // ========================================================
        // MIDI 7-BIT -> CONTROLLER EVENT
        // ========================================================

        auto controllerEvent =
            m_processor->process(midiEvent);

        if (!controllerEvent)
        {
            continue;
        }

        // ========================================================
        // EVENT BUS
        // ========================================================

        m_eventBus.publish(
            *controllerEvent);

        // ========================================================
        // ENCODER EVENT
        // ========================================================

        if (
            controllerEvent->type() ==
            EventType::Encoder)
        {
            const auto* encoderEvent =
                dynamic_cast<const EncoderEvent*>(
                    controllerEvent.get());

            if (!encoderEvent)
            {
                continue;
            }

            switch (encoderEvent->encoder())
            {
                case Encoder::Browse:
                {
                    Logger::info(
                        "BROWSE -> delta " +
                        std::to_string(
                            encoderEvent->delta()));

                    break;
                }
            }

            continue;
        }

        // ========================================================
        // JOG WHEEL EVENT
        // ========================================================

        if (
            controllerEvent->type() ==
            EventType::JogWheel)
        {
            const auto* jogWheelEvent =
                dynamic_cast<const JogWheelEvent*>(
                    controllerEvent.get());

            if (!jogWheelEvent)
            {
                continue;
            }

            std::string deck =
                "Unknown";

            if (
                jogWheelEvent->deck() ==
                Deck::A)
            {
                deck = "A";
            }
            else if (
                jogWheelEvent->deck() ==
                Deck::B)
            {
                deck = "B";
            }

            switch (jogWheelEvent->jogWheel())
            {
                // =================================================
                // NORMAL JOG ROTATION
                // =================================================

                case JogWheel::Platter:
                {
                    Logger::info(
                        "JOG Deck " +
                        deck +
                        " -> delta " +
                        std::to_string(
                            jogWheelEvent->delta()));

                    break;
                }

                // =================================================
                // SCRATCH ROTATION
                // =================================================

                case JogWheel::Scratch:
                {
                    Logger::info(
                        "JOG SCRATCH Deck " +
                        deck +
                        " -> delta " +
                        std::to_string(
                            jogWheelEvent->delta()));

                    break;
                }

                // =================================================
                // SEARCH ROTATION
                // =================================================

                case JogWheel::Search:
                {
                    Logger::info(
                        "JOG SEARCH Deck " +
                        deck +
                        " -> delta " +
                        std::to_string(
                            jogWheelEvent->delta()));

                    break;
                }
            }

            continue;
        }

        // ========================================================
        // JOG TOUCH EVENT
        // ========================================================

        if (
            controllerEvent->type() ==
            EventType::JogTouch)
        {
            const auto* jogTouchEvent =
                dynamic_cast<const JogTouchEvent*>(
                    controllerEvent.get());

            if (!jogTouchEvent)
            {
                continue;
            }

            std::string deck =
                "Unknown";

            if (
                jogTouchEvent->deck() ==
                Deck::A)
            {
                deck = "A";
            }
            else if (
                jogTouchEvent->deck() ==
                Deck::B)
            {
                deck = "B";
            }

            const std::string state =
                jogTouchEvent->state() ==
                        JogTouchState::Touched
                    ? "TOUCHED"
                    : "RELEASED";

            Logger::info(
                "JOG TOUCH Deck " +
                deck +
                " -> " +
                state);

            continue;
        }
    }
}

void MidiService::shutdown()
{
    m_input.reset();
    m_processor.reset();
    m_profile.reset();

    m_capture.reset();

    Logger::info(
        "MidiService shutdown.");
}

} // namespace OpenDJ