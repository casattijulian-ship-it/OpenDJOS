#include "MidiService.hpp"

#include "Core/Logging/Logger.hpp"

#include "Controllers/Profiles/DDJ400Profile.hpp"

#include <exception>
#include <memory>
#include <string>

namespace OpenDJ
{

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

                m_profile = std::make_unique<DDJ400Profile>();

                m_processor = std::make_unique<MidiProcessor>(*m_profile);

                m_input = std::make_unique<MidiInput>(device);

                if (m_input->open())
                {
                    Logger::info("Connected to DDJ-400.");
                }
                else
                {
                    Logger::warning("Failed to open DDJ-400.");

                    m_input.reset();
                    m_processor.reset();
                    m_profile.reset();
                }

                break;
            }
        }

        if (!m_input)
        {
            Logger::warning("No DDJ-400 controller found.");
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
    if (!m_input)
    {
        return;
    }

    MidiEvent event;

    while (m_input->poll(event))
    {
        Logger::debug(
            "MIDI -> type=" +
            std::to_string(static_cast<int>(event.type)) +
            " channel=" +
            std::to_string(event.channel) +
            " number=" +
            std::to_string(event.number) +
            " value=" +
            std::to_string(event.value));
    }
}

void MidiService::shutdown()
{
    m_input.reset();
    m_processor.reset();
    m_profile.reset();

    Logger::info("MidiService shutdown.");
}

} // namespace OpenDJ