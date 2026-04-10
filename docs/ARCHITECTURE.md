# 🧠 Taskr Architecture

This document explains how Taskr is structured internally and how the system is designed to evolve over time.

Taskr is a native Windows automation engine built in C++ using WinAPI.  
The architecture is intentionally minimal, modular, and built from the ground up without external frameworks.

---

## 🏗️ Project Architecture

```bash
taskr/
│
├── src/
│   ├── core/
│   │   ├── engine/
│   │   │   ├── task_engine.cpp
│   │   │   ├── task_engine.h
│   │   │
│   │   ├── input/
│   │   │   ├── keyboard.cpp
│   │   │   ├── keyboard.h
│   │   │   ├── mouse.cpp
│   │   │   ├── mouse.h
│   │   │
│   │   ├── recorder/
│   │   │   ├── recorder.cpp
│   │   │   ├── recorder.h
│   │   │
│   │   ├── player/
│   │   │   ├── player.cpp
│   │   │   ├── player.h
│   │
│   ├── platform/
│   │   ├── windows/
│   │   │   ├── win_main.cpp
│   │   │   ├── win_hooks.cpp
│   │   │   ├── win_hooks.h
│   │
│   ├── utils/
│   │   ├── logger.cpp
│   │   ├── logger.h
│   │   ├── time.cpp
│   │   ├── time.h
│   │
│   ├── main.cpp
│
├── docs/
│   ├── ARCHITECTURE.md
│   ├── CONTRIBUTING.md
│   ├── CODE_OF_CONDUCT.md
│   ├── COMMIT_CONVENTION.md
│   ├── ROADMAP.md
│
├── build/
│   ├── build.bat
│   ├── clean.bat
│
├── assets/
├── tests/
├── .gitignore
├── LICENSE
├── README.md
```

---

## 📌 Design Philosophy

From the beginning, I wanted Taskr to stay:

- **Fully native** (no external runtimes or dependencies)  
- **Lightweight and fast**  
- **Modular instead of monolithic**  
- **Simple to extend over time**  
- **Close to the system layer (Windows API level)**  

The goal is not abstraction — it’s control and clarity.

---

## 🧱 High-Level Overview

Taskr is structured as a layered system:

```
User Input
   ↓
Platform Layer (Windows API)
   ↓
Core Engine
   ↓
Modules (Input / Recorder / Player)
   ↓
Rendering System (UI)
```

Each layer has a very specific responsibility and does not directly depend on higher-level logic.

---

## 🪟 1. Platform Layer (Windows)

**Location:** `src/platform/windows/`

This is the lowest level of the system.

It handles:

- Window creation (WinAPI)
- Message loop (WinMain / WndProc)
- System events (keyboard, mouse, resize)
- Native Windows integration

### Key Idea
This layer is completely Windows-specific and isolates all OS-level behavior.

Nothing above this layer should directly call WinAPI unless necessary.

---

## ⚙️ 2. Core Engine

**Location:** `src/core/`

This is the brain of Taskr.

It manages:

- Task execution flow
- System coordination between modules
- Input → processing → output pipeline
- Internal state management

### Key Idea
The core engine does NOT handle raw input or rendering.

It only coordinates systems.

---

## ⌨️ 3. Input System

**Location:** `src/core/input/`

This module handles all user interaction:

- Keyboard hooks
- Mouse hooks
- Input normalization
- Event structuring (turning raw input into usable data)

### Output Example
Instead of raw events, input becomes structured like:

```
KEY_DOWN: W
MOUSE_MOVE: (x, y)
KEY_UP: W
```

### Key Idea
Input is converted into a clean internal format before anything else touches it.

---

## 🎥 4. Recorder System

**Location:** `src/core/recorder/`

This system captures input streams and stores them.

It handles:

- Start / stop recording sessions
- Buffering input events
- Timestamp tracking
- Saving structured data

### Key Idea
Recording is just “storing input over time”, nothing more.

---

## ▶️ 5. Player System

**Location:** `src/core/player/`

This system replays recorded input.

It handles:

- Event replay execution
- Timing accuracy
- Playback control (start / stop / pause)
- Looping sequences

### Key Idea
Player is the inverse of Recorder.

Recorder → stores input  
Player → reproduces input  

---

## 🎨 6. Rendering System (UI)

**Location:** `src/main.cpp` (initially)

This handles the visual part of Taskr:

- Window drawing (GDI)
- Text rendering
- UI refresh cycle (WM_PAINT)
- Responsive resizing behavior

### Key Idea
UI is separate from logic — it only displays state.

---

## 🧰 7. Utils Layer

**Location:** `src/utils/`

Shared helper systems:

- Logging system
- Time utilities
- Common helpers used across modules

---

## 🧠 Data Flow

A simplified flow of how Taskr works:

```
[User Input]
     ↓
[Windows API Hooks]
     ↓
[Input System]
     ↓
[Recorder OR Core Engine]
     ↓
[Player System (optional replay)]
     ↓
[Rendering System updates UI]
```

---

## 🧩 Module Independence Rules

To keep the system clean:

- Core does NOT depend on UI  
- Input does NOT depend on Recorder or Player  
- Platform layer is isolated from all logic  
- UI only reads state, never controls logic directly  

This prevents tight coupling and keeps the system scalable.

---

## ⚡ Performance Design

Taskr is designed to stay lightweight:

- No external libraries
- Minimal memory overhead
- Event-driven system (not polling-heavy)
- Direct system-level calls where needed
- Optimized for small binary size (~1MB target)

---

## 🧠 Current State

Right now:

- UI system is working (WinAPI + GDI)
- Core structure is in place
- Input system is the next missing foundation piece

Everything else depends on input being properly implemented.

---

## 🚀 Long-Term Direction

The goal is not to make a complicated automation framework.

The goal is:

> a fast, minimal, native Windows automation engine that gives full control without unnecessary complexity.

Taskr should stay close to the system, predictable, and easy to extend without becoming bloated.

---

## 📌 Summary

Taskr is built around one idea:

- capture input  
- structure it  
- replay or automate it  
- keep everything minimal and native  

That simplicity is the entire architecture.