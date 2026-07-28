#include "MidiDevice.hpp"

namespace OpenDJ
{

MidiDevice::MidiDevice(const std::string& name,
                       int client,
                       int port,
                       unsigned int type,
                       unsigned int capabilities)
    : m_name(name),
      m_client(client),
      m_port(port),
      m_type(type),
      m_capabilities(capabilities)
{
}

const std::string& MidiDevice::name() const
{
    return m_name;
}

int MidiDevice::client() const
{
    return m_client;
}

int MidiDevice::port() const
{
    return m_port;
}

unsigned int MidiDevice::type() const
{
    return m_type;
}

unsigned int MidiDevice::capabilities() const
{
    return m_capabilities;
}

} // namespace OpenDJ