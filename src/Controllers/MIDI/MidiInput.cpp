#include "MidiInput.hpp"

#include <iostream>

namespace OpenDJ
{

MidiInput::MidiInput(const MidiDevice& device)
    : m_device(device)
{
}

MidiInput::~MidiInput()
{
    close();
}

bool MidiInput::open()
{
    if (m_sequencer != nullptr)
    {
        return true;
    }

    int result = snd_seq_open(
        &m_sequencer,
        "default",
        SND_SEQ_OPEN_DUPLEX,
        SND_SEQ_NONBLOCK);

    if (result < 0)
    {
        std::cout << "snd_seq_open() failed: "
                  << snd_strerror(result)
                  << std::endl;

        m_sequencer = nullptr;
        return false;
    }

    snd_seq_set_client_name(
        m_sequencer,
        "OpenDJ OS Input");

    m_port = snd_seq_create_simple_port(
        m_sequencer,
        "Input",
        SND_SEQ_PORT_CAP_WRITE |
        SND_SEQ_PORT_CAP_SUBS_WRITE,
        SND_SEQ_PORT_TYPE_APPLICATION);

    if (m_port < 0)
    {
        std::cout << "Failed to create input port: "
                  << snd_strerror(m_port)
                  << std::endl;

        snd_seq_close(m_sequencer);
        m_sequencer = nullptr;
        return false;
    }

    result = snd_seq_connect_from(
        m_sequencer,
        m_port,
        m_device.client(),
        m_device.port());

    if (result < 0)
    {
        std::cout << "Connection failed: "
                  << snd_strerror(result)
                  << std::endl;

        close();
        return false;
    }

    std::cout << "Connected successfully to "
              << m_device.name()
              << " (client "
              << m_device.client()
              << ", port "
              << m_device.port()
              << ")"
              << std::endl;

    return true;
}

void MidiInput::close()
{
    if (m_sequencer != nullptr)
    {
        snd_seq_close(m_sequencer);
        m_sequencer = nullptr;
    }

    m_port = -1;
}

bool MidiInput::poll(MidiEvent& event)
{
    if (m_sequencer == nullptr)
    {
        return false;
    }

    if (snd_seq_event_input_pending(m_sequencer, 1) <= 0)
    {
        return false;
    }

    snd_seq_event_t* alsaEvent = nullptr;

    int result = snd_seq_event_input(
        m_sequencer,
        &alsaEvent);

    if (result < 0 || alsaEvent == nullptr)
    {
        return false;
    }

    switch (alsaEvent->type)
    {
        case SND_SEQ_EVENT_NOTEON:
        {
            event.type = MidiMessageType::NoteOn;
            event.channel = alsaEvent->data.note.channel;
            event.number = alsaEvent->data.note.note;
            event.value = alsaEvent->data.note.velocity;
            return true;
        }

        case SND_SEQ_EVENT_NOTEOFF:
        {
            event.type = MidiMessageType::NoteOff;
            event.channel = alsaEvent->data.note.channel;
            event.number = alsaEvent->data.note.note;
            event.value = alsaEvent->data.note.velocity;
            return true;
        }

        case SND_SEQ_EVENT_CONTROLLER:
        {
            event.type = MidiMessageType::ControlChange;
            event.channel = alsaEvent->data.control.channel;
            event.number = alsaEvent->data.control.param;
            event.value = alsaEvent->data.control.value;
            return true;
        }

        default:
            break;
    }

    return false;
}

bool MidiInput::isOpen() const
{
    return m_sequencer != nullptr;
}

} // namespace OpenDJ