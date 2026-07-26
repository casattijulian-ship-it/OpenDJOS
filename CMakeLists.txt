cmake_minimum_required(VERSION 3.20)

project(OpenDJOS VERSION 0.1.0 LANGUAGES CXX)

# ============================================================
# Configuración de C++
# ============================================================

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

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

    src/Core/Events/Event.cpp
    src/Core/Events/EventBus.cpp

    src/Core/Logging/Logger.cpp

    src/Core/Services/ServiceManager.cpp

    src/Core/Version/Version.cpp
)

# ============================================================
# Directorios de inclusión
# ============================================================

target_include_directories(OpenDJOS PRIVATE
    src
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