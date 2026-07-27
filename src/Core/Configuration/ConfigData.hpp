#pragma once

#include <string>

namespace OpenDJ
{

class ConfigData
{
public:

    ConfigData();

    // General
    const std::string& applicationName() const;
    void setApplicationName(const std::string& name);

    // Audio
    int sampleRate() const;
    void setSampleRate(int sampleRate);

    int bufferSize() const;
    void setBufferSize(int bufferSize);

    // Library
    const std::string& musicDirectory() const;
    void setMusicDirectory(const std::string& directory);

private:

    std::string m_applicationName;

    int m_sampleRate;

    int m_bufferSize;

    std::string m_musicDirectory;
};

}