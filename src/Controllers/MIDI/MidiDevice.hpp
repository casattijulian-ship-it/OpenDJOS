#pragma once

#include <string>

namespace OpenDJ
{

class MidiDevice
{
public:

    std::string name() const;

    int client() const;

    int port() const;

private:

    std::string m_name;

    int m_client = -1;

    int m_port = -1;
};

}