#pragma once

#include <string>

namespace OpenDJ
{

class MidiDevice
{
public:

    MidiDevice() = default;

    MidiDevice(const std::string& name,
               int client,
               int port,
               unsigned int type,
               unsigned int capabilities);

    const std::string& name() const;

    int client() const;

    int port() const;

    unsigned int type() const;

    unsigned int capabilities() const;

private:

    std::string m_name;

    int m_client = -1;

    int m_port = -1;

    unsigned int m_type = 0;

    unsigned int m_capabilities = 0;
};

} // namespace OpenDJ