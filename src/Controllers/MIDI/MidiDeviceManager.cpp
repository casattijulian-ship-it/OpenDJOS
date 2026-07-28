#include "MidiDeviceManager.hpp"

#include <stdexcept>

namespace OpenDJ
{

MidiDeviceManager::MidiDeviceManager()
{
    const int result = snd_seq_open(
        &m_sequencer,
        "default",
        SND_SEQ_OPEN_DUPLEX,
        0);

    if (result < 0)
    {
        throw std::runtime_error(
            std::string("Failed to open ALSA sequencer: ") +
            snd_strerror(result));
    }

    snd_seq_set_client_name(m_sequencer, "OpenDJ OS");
}

MidiDeviceManager::~MidiDeviceManager()
{
    if (m_sequencer != nullptr)
    {
        snd_seq_close(m_sequencer);
        m_sequencer = nullptr;
    }
}

std::vector<MidiDevice> MidiDeviceManager::enumerate() const
{
    std::vector<MidiDevice> devices;

    snd_seq_client_info_t* clientInfo;
    snd_seq_port_info_t* portInfo;

    snd_seq_client_info_alloca(&clientInfo);
    snd_seq_port_info_alloca(&portInfo);

    snd_seq_client_info_set_client(clientInfo, -1);

    while (snd_seq_query_next_client(m_sequencer, clientInfo) >= 0)
    {
        const int client = snd_seq_client_info_get_client(clientInfo);

        snd_seq_port_info_set_client(portInfo, client);
        snd_seq_port_info_set_port(portInfo, -1);

        while (snd_seq_query_next_port(m_sequencer, portInfo) >= 0)
        {
            const unsigned int capability =
                snd_seq_port_info_get_capability(portInfo);

            const unsigned int type =
                snd_seq_port_info_get_type(portInfo);

            if ((capability & SND_SEQ_PORT_CAP_READ) == 0)
            {
                continue;
            }

            const std::string name =
                snd_seq_port_info_get_name(portInfo);

            // Ignorar puertos internos de ALSA
            if (name == "Timer" ||
                name == "Announce" ||
                name == "Midi Through Port-0")
            {
                continue;
            }

            // Ignorar puertos sin nombre
            if (name.empty())
            {
                continue;
            }

            devices.emplace_back(
                name,
                client,
                snd_seq_port_info_get_port(portInfo),
                type,
                capability);
        }
    }

    return devices;
}

std::optional<MidiDevice> MidiDeviceManager::findByName(const std::string& name) const
{
    const auto devices = enumerate();

    for (const auto& device : devices)
    {
        if (device.name() == name)
        {
            return device;
        }
    }

    return std::nullopt;
}

} // namespace OpenDJ