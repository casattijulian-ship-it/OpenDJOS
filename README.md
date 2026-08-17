# OpenDJ OS

**Open-source DJ software platform built in C++20 with a modular architecture and hardware controller integration.**

OpenDJ OS is an experimental DJ platform focused on building a modular, hardware-oriented environment for digital DJing.

The project is being developed from the ground up around clear software boundaries between the core system, controller input, MIDI processing, playback, library management and graphical presentation.

> **Status:** Active development 🚧

---

## Overview

OpenDJ OS aims to provide a complete DJ environment capable of running on dedicated hardware while supporting external DJ controllers.

The project is currently being developed in **C++20** using **CMake**, with Linux as the primary development environment.

The first hardware development target is the **Pioneer DDJ-400**, which is being used to develop and validate the controller abstraction and MIDI input systems.

The long-term objective is to build a system where the DJ hardware is not tightly coupled to the application logic, allowing different controllers and hardware configurations to be supported through a common abstraction layer.

---

## Architecture

The project follows a modular architecture designed to keep hardware, application logic and presentation separated.

```text
                         ┌──────────────────────┐
                         │      OpenDJ OS       │
                         │      Application     │
                         └──────────┬───────────┘
                                    │
              ┌─────────────────────┼─────────────────────┐
              │                     │                     │
              ▼                     ▼                     ▼
      ┌───────────────┐     ┌───────────────┐     ┌───────────────┐
      │  Controller   │     │    Display    │     │    Library    │
      │  Abstraction  │     │    Engine     │     │    Engine     │
      └───────┬───────┘     └───────────────┘     └───────────────┘
              │
              ▼
      ┌───────────────┐
      │   MIDI Layer  │
      └───────┬───────┘
              │
              ▼
      ┌───────────────────┐
      │   DJ Controller   │
      │   Pioneer DDJ-400 │
      └───────────────────┘
```

The architecture is intended to evolve as the project grows.

### Core

The Core layer provides the foundation required by the rest of the system.

Current architectural areas include:

* Application lifecycle
* Version information
* Logging
* Configuration
* Event handling
* Common system services

### Controller Abstraction Layer

The Controller Abstraction Layer separates physical DJ hardware from the rest of the application.

Instead of allowing the rest of OpenDJ OS to depend directly on a specific controller, hardware input is converted into standardized controller events.

Conceptually:

```text
Physical Controller
        │
        ▼
MIDI / Hardware Input
        │
        ▼
Controller Abstraction
        │
        ▼
Standardized Events
        │
        ├── Jog
        ├── Scratch
        ├── Play
        ├── Cue
        ├── Pads
        ├── Tempo
        ├── Loop
        └── Browser
```

This allows additional controllers to be integrated without redesigning the rest of the application.

### MIDI

The MIDI layer is responsible for processing controller MIDI input and converting raw MIDI messages into meaningful application events.

The system is being developed with controller-specific behavior separated from generic MIDI processing.

### Playback Engine

The Playback Engine will be responsible for audio playback and deck-related functionality.

Planned responsibilities include:

* Audio playback
* Deck state
* BPM
* Beatgrid
* Time stretching
* Position control
* Looping
* Audio routing

### Library Engine

The Library Engine will provide the infrastructure required to manage a DJ music collection.

Planned functionality includes:

* Track database
* Metadata
* BPM information
* Track analysis
* Search
* Playlists
* Waveform information

### Display Engine

The Display Engine will provide the graphical representation of the DJ system.

Its purpose is to remain independent from the underlying controller hardware and application logic.

Planned areas include:

* Deck interface
* Waveforms
* Browser
* Track information
* Mixer information
* Performance controls
* UI event handling

---

# Current Development Status

OpenDJ OS is currently in the **controller and core architecture development phase**.

The Pioneer DDJ-400 is being used as the primary hardware development target.

## Controller Integration

Current development includes:

* [x] Controller abstraction
* [x] MIDI event processing
* [x] Pioneer DDJ-400 integration
* [x] Jog wheel input
* [x] Jog touch detection
* [x] Scratch detection
* [x] Search controls
* [x] Tempo controls
* [x] Play / Cue / Sync controls
* [x] Loop-related controls
* [x] Performance pad input
* [x] Browser controls
* [x] Mixer controls
* [ ] Additional controller implementations

## Core

Current architectural work includes:

* [x] C++20 project foundation
* [x] CMake build system
* [x] Project versioning
* [x] Logging foundation
* [x] Core module organization
* [ ] Configuration system
* [ ] Event Bus
* [ ] Application lifecycle
* [ ] Expanded service infrastructure

## Audio

Planned:

* [ ] Playback engine
* [ ] Audio routing
* [ ] Deck state management
* [ ] Beatgrid
* [ ] Time stretching
* [ ] Audio analysis
* [ ] Effects

## Library

Planned:

* [ ] Music database
* [ ] Metadata management
* [ ] BPM analysis
* [ ] Track analysis
* [ ] Search
* [ ] Playlists
* [ ] Waveform generation

## Display

Planned:

* [ ] Display Engine
* [ ] Deck UI
* [ ] Browser UI
* [ ] Waveform rendering
* [ ] Track information
* [ ] UI Event Manager

---

# Hardware

## Pioneer DDJ-400

The DDJ-400 is currently the primary controller used for OpenDJ OS development and hardware validation.

The controller provides a useful development target because it exposes a wide range of DJ interaction patterns through MIDI and hardware controls.

Current areas being integrated include:

### Decks

* Play
* Cue
* Sync
* Shift
* Tempo
* Jog wheel
* Jog touch
* Scratch
* Search
* Loop
* Cue / Loop controls

### Performance

The DDJ-400 provides **8 performance pads per deck**.

Current development covers:

* Pads 1–8
* Hot Cue
* Beat Loop
* Beat Jump
* Sampler

### Mixer

* Trim
* EQ High
* EQ Mid
* EQ Low
* Filter
* Channel Fader
* Crossfader

### Browser

* Rotary encoder
* Rotary press
* Load A
* Load B

### Effects

* Beat
* FX Select
* Channel Select
* FX On / Off

---

# Project Structure

The repository is organized around separating source code, hardware definitions and documentation.

```text
OpenDJOS/
│
├── assets/
│   └── controllers/
│       └── Pioneer/
│
├── docs/
│   └── hardware/
│
├── src/
│   ├── Core/
│   ├── Controllers/
│   └── ...
│
├── CMakeLists.txt
├── README.md
└── .gitignore
```

The structure will evolve as additional engines and services are implemented.

---

# Technology

OpenDJ OS is currently built around:

| Technology | Purpose                                    |
| ---------- | ------------------------------------------ |
| **C++20**  | Core application and system implementation |
| **CMake**  | Build system                               |
| **Linux**  | Primary development platform               |
| **MIDI**   | DJ controller communication                |
| **Git**    | Version control                            |

The architecture is being designed with portability and hardware integration in mind.

---

# Building

## Requirements

A development environment should provide:

* Linux
* C++20-compatible compiler
* CMake
* Git

Verify the required tools:

```bash
g++ --version
cmake --version
git --version
```

## Clone the repository

```bash
git clone https://github.com/casatjulian-ship-it/OpenDJOS.git
cd OpenDJOS
```

## Configure the project

```bash
cmake -S . -B build
```

## Build

```bash
cmake --build build -j$(nproc)
```

The project is currently under active development, so build and runtime requirements may change as new subsystems are introduced.

---

# Development Philosophy

OpenDJ OS is being developed around several principles.

### Modularity

Subsystems should have clear responsibilities and interfaces.

A controller implementation should not dictate how the playback engine or user interface works.

### Hardware abstraction

Physical hardware should be separated from application logic.

This makes it possible to support multiple DJ controllers through the same application architecture.

### Low-latency interaction

DJ software requires responsive interaction between physical controls and application state.

Controller input and event processing are therefore treated as important parts of the system architecture.

### Incremental development

The project is being developed subsystem by subsystem rather than attempting to implement the entire DJ application at once.

The controller layer is currently one of the main areas of development.

### Open source

The project is developed publicly so that the architecture, implementation decisions and development process can be inspected over time.

---

# Roadmap

The roadmap is intentionally incremental.

## Phase 1 — Foundation

* [x] Repository
* [x] C++20 foundation
* [x] CMake
* [x] Core structure
* [x] Version system
* [x] Logger
* [ ] Configuration
* [ ] Event Bus
* [ ] Application lifecycle

## Phase 2 — Controller System

* [x] Controller abstraction
* [x] MIDI processing
* [x] DDJ-400 integration
* [x] Jog wheel
* [x] Jog touch
* [x] Scratch
* [x] Search
* [x] Performance Pads
* [x] Browser controls
* [ ] Additional controllers

## Phase 3 — Playback

* [ ] Playback engine
* [ ] Deck management
* [ ] Audio pipeline
* [ ] BPM
* [ ] Beatgrid
* [ ] Time stretching
* [ ] Loop engine
* [ ] Audio routing

## Phase 4 — Library

* [ ] Music database
* [ ] Metadata
* [ ] Track analysis
* [ ] BPM analysis
* [ ] Search
* [ ] Playlists
* [ ] Waveforms

## Phase 5 — Display

* [ ] Display Engine
* [ ] Deck interface
* [ ] Waveforms
* [ ] Browser
* [ ] Library interface
* [ ] Mixer interface
* [ ] UI Event Manager

## Phase 6 — Dedicated Hardware

The long-term direction is to explore OpenDJ OS running as a dedicated DJ system.

Potential hardware architecture:

```text
┌─────────────────────────────────────────────┐
│                 OpenDJ OS                   │
│                                             │
│  Display ── Core ── Playback ── Library    │
│                │                            │
│        Controller Abstraction               │
└────────────────┬────────────────────────────┘
                 │
                 ▼
        External DJ Controller
```

Dedicated hardware development will be considered once the software architecture and core functionality are sufficiently mature.

---

# Documentation

More detailed technical documentation is available in the repository.

Current documentation areas include:

* Hardware
* Controller integration
* MIDI mappings
* Core architecture
* Playback architecture
* Library architecture
* Display architecture

Controller-specific information should be kept separate from the main README so that this page remains focused on the project as a whole.

---

# DDJ-400 MIDI Documentation

The complete DDJ-400 MIDI mapping is maintained separately from this README.

It covers:

* Mixer controls
* Deck controls
* Performance Pads
* Browser controls
* Effects
* MIDI values
* Controller events

See the hardware documentation for the complete mapping.

---

# Project Status

OpenDJ OS is **not yet a production-ready DJ application**.

It is an active development project focused on building the architecture and infrastructure required for a complete open-source DJ platform.

The current priority is establishing a robust controller abstraction and core architecture before implementing the higher-level playback, library and graphical systems.

---

# Contributing

OpenDJ OS is currently primarily developed as an independent project.

As the architecture matures, contribution guidelines and development documentation will be expanded.

If you want to experiment with the code, improvements to architecture, controller support, MIDI processing and documentation are particularly relevant areas.

---

# License

License information will be added as the project reaches the appropriate stage for public distribution.

---

## OpenDJ OS

**An open-source DJ platform built from the ground up.**

C++20 · Linux · MIDI · Modular Architecture · DJ Hardware
