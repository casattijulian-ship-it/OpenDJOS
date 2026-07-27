#include "ConfigData.hpp"

namespace OpenDJ
{

ConfigData::ConfigData()
    : m_applicationName("OpenDJ OS"),
      m_sampleRate(44100),
      m_bufferSize(512),
      m_musicDirectory("./Music")
{
}

const std::string& ConfigData::applicationName() const
{
    return m_applicationName;
}

void ConfigData::setApplicationName(const std::string& name)
{
    m_applicationName = name;
}

int ConfigData::sampleRate() const
{
    return m_sampleRate;
}

void ConfigData::setSampleRate(int sampleRate)
{
    m_sampleRate = sampleRate;
}

int ConfigData::bufferSize() const
{
    return m_bufferSize;
}

void ConfigData::setBufferSize(int bufferSize)
{
    m_bufferSize = bufferSize;
}

const std::string& ConfigData::musicDirectory() const
{
    return m_musicDirectory;
}

void ConfigData::setMusicDirectory(const std::string& directory)
{
    m_musicDirectory = directory;
}

}