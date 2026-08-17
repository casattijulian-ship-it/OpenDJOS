cmake_minimum_required(VERSION 3.20)

project(OpenDJOS VERSION 0.1.0 LANGUAGES CXX)

# ============================================================
# Configuración de C++
# ============================================================

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# ============================================================
# Dependencias
# ============================================================

find_package(PkgConfig REQUIRED)
pkg_check_modules(ALSA REQUIRED alsa)

# ============================================================
# Ejecutable principal
# ============================================================

add_executable(OpenDJOS

    # Main
    src/main.cpp

    # ========================================================
    # Core
    # ========================================================

    src/Core/Application/Application.cpp

    src/Core/Configuration/Configuration.cpp
    src/Core/Configuration/ConfigData.cpp
    src/Core/Configuration/ConfigLoader.cpp
    src/Core/Configuration/ConfigValidator.cpp

    src/Core/Events/Event.cpp
    src/Core/Events/EventBus.cpp

    src/Core/Logging/Logger.cpp

    src/Core/Services/ServiceManager.cpp
    src/Core/Services/MidiService.cpp

    src/Core/Version/Version.cpp

    # ========================================================
    # Controllers
    # ========================================================

    # Mapping
    src/Controllers/Mapping/ControllerEvent.cpp
    src/Controllers/Mapping/ControllerMapper.cpp
    src/Controllers/Mapping/ButtonEvent.cpp
    src/Controllers/Mapping/FaderEvent.cpp
    src/Controllers/Mapping/KnobEvent.cpp
    src/Controllers/Mapping/JogWheelEvent.cpp
    src/Controllers/Mapping/JogTouchEvent.cpp
    src/Controllers/Mapping/EncoderEvent.cpp
    src/Controllers/Mapping/PerformancePadEvent.cpp

    # Handlers
    src/Controllers/Handlers/PerformancePadHandler.cpp
    src/Controllers/Handlers/PerformancePadActionExecutor.cpp
    src/Controllers/Handlers/ButtonHandler.cpp
    src/Controllers/Handlers/ButtonActionExecutor.cpp
    src/Controllers/Handlers/JogWheelHandler.cpp
    src/Controllers/Handlers/JogWheelActionExecutor.cpp
    
    # State
    src/Controllers/State/ModifierState.cpp
    
    # MIDI
    src/Controllers/MIDI/MidiDevice.cpp
    src/Controllers/MIDI/MidiDeviceManager.cpp
    src/Controllers/MIDI/MidiInput.cpp
    src/Controllers/MIDI/MidiOutput.cpp
    src/Controllers/MIDI/MidiProcessor.cpp
    src/Controllers/MIDI/Midi14BitProcessor.cpp
    src/Controllers/MIDI/MidiCapture.cpp

    # Profiles
    src/Controllers/Profiles/ControllerProfile.cpp
    src/Controllers/Profiles/ProfileLoader.cpp
    src/Controllers/Profiles/DDJ400Profile.cpp

    # Drivers
    # (por ahora ControllerDriver es una interfaz, no necesita .cpp)
)

# ============================================================
# Directorios de inclusión
# ============================================================

target_include_directories(OpenDJOS PRIVATE
    src
    ${ALSA_INCLUDE_DIRS}
)

# ============================================================
# Enlace de bibliotecas
# ============================================================

target_link_libraries(OpenDJOS PRIVATE
    ${ALSA_LIBRARIES}
)

# ============================================================
# Advertencias del compilador
# ============================================================

if(MSVC)
    target_compile_options(OpenDJOS PRIVATE /W4)
else()
    target_compile_options(OpenDJOS PRIVATE
        -Wall
        -Wextra
        -Wpedantic
    )
endif()