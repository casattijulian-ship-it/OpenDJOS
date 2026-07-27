#include "ConfigLoader.hpp"

namespace OpenDJ
{

bool ConfigLoader::load(ConfigData& config)
{
    // Valores por defecto.
    // En el futuro aquí leeremos config.json.

    config.setApplicationName("OpenDJ OS");
    config.setSampleRate(44100);
    config.setBufferSize(512);
    config.setMusicDirectory("./Music");

    return true;
}

}