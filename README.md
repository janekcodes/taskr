# ⚙️ Taskr

[![License: MIT](https://img.shields.io/badge/License-MIT-yellow.svg)](LICENSE)
[![Status](https://img.shields.io/badge/status-in%20development-orange)](https://github.com/janekcodes/taskr)
[![Maintenance](https://img.shields.io/badge/Maintained-Active-blue)](https://github.com/janekcodes/taskr)
[![Version](https://img.shields.io/badge/version-0.1-blue)](https://github.com/janekcodes/taskr/releases)
[![Platform](https://img.shields.io/badge/platform-Windows-blue)](https://www.microsoft.com/windows)
[![Language](https://img.shields.io/badge/language-C++-blue.svg)]()
[![Build](https://img.shields.io/badge/build-MinGW--w64-green)]()
[![PRs Welcome](https://img.shields.io/badge/PRs-welcome-brightgreen.svg)](https://github.com/janekcodes/taskr/pulls)
[![Issues](https://img.shields.io/github/issues/janekcodes/taskr)](https://github.com/janekcodes/taskr/issues)
[![Last Commit](https://img.shields.io/github/last-commit/janekcodes/taskr)](https://github.com/janekcodes/taskr/commits/main)
[![Security](https://img.shields.io/badge/Security-Policy-red)](SECURITY.md)
[![Contributors](https://img.shields.io/github/contributors/janekcodes/taskr)](https://github.com/janekcodes/taskr/graphs/contributors)
[![GitHub stars](https://img.shields.io/github/stars/janekcodes/taskr)](https://github.com/janekcodes/taskr/stargazers)
[![GitHub forks](https://img.shields.io/github/forks/janekcodes/taskr)](https://github.com/janekcodes/taskr/network)

> A fast, compact, and highly optimized Windows automation tool built to simplify repetitive tasks.

---

## 📌 Navigation

- 🧠 [Roadmap](docs/ROADMAP.md)
- 🏗️ [Architecture](docs/ARCHITECTURE.md)
- 🤝 [Contributing](docs/CONTRIBUTING.md)
- 🧾 [Commit Convention](docs/COMMIT_CONVENTION.md)
- 📜 [Code of Conduct](docs/CODE_OF_CONDUCT.md)
- 📜 [License](LICENSE)

---

## 📌 Motivation

As I started using different automation tools on Windows, I kept running into the same frustrations.

Most tools I tried were either:
- too heavy for simple tasks  
- overly complicated to set up or understand  
- dependent on external runtimes or scripting environments  
- or limited in how much control I actually had over the system  

At some point, I realized I wasn’t just looking for “another tool” — I was trying to find something that felt simple, fast, and fully under my control.

That’s what led me to start building Taskr.

I wanted to create a **minimal, native Windows automation engine in C++** that focuses on doing one thing properly: making repetitive tasks easier without adding unnecessary complexity.

This project started as a small experiment with WinAPI and low-level input handling, but as I worked on it, it naturally evolved into something bigger.

The goal is to build a foundation for automation that is:
- fast and lightweight  
- simple to understand and extend  
- fully native to Windows  
- and not dependent on external frameworks or runtimes  

Taskr is still early, but the long-term vision is clear:

> a clean, reliable automation engine that stays minimal at its core while growing in capability over time.

---

## ✨ Features (Current Phase)

### 🧱 Core System
- Native WinAPI window (no frameworks)
- Fully resizable desktop UI
- Custom rendering system (GDI)
- Responsive layout scaling
- Clean message loop architecture

### 🎨 UI System
- Centered dynamic text rendering
- Responsive font scaling
- Minimal white UI design
- Status display ("Task: In Progress")

### ⚙️ Build System
- MinGW-w64 compatible
- One-command build via `.bat`
- Optimized compilation (`-Os -s`)

---

## 🧠 Vision

Taskr aims to evolve into a full automation engine similar to:

- TinyTask (lightweight macro recorder)
- AutoHotkey (automation scripting engine)

but focused on:

- ⚡ Native performance (C++)
- 📦 Minimal binary size (~1MB target)
- 🧠 Simplicity and clarity
- 🔧 Full system-level control

---

## 🧰 Tech Stack

### 💻 Core Language
- C++ (17/20 standard, depending on compiler support)

### 🪟 Platform
- Windows API (WinAPI)
- GDI (Graphics Device Interface) for rendering
- User32 / Kernel32 system libraries

### ⚙️ Build System
- MinGW-w64 (GCC 15.x)
- Batch scripting (`build.bat`) for automation

### 🎨 UI & Rendering
- Native WinAPI windowing system
- GDI text rendering (CreateFont, DrawTextW)
- Manual repaint system (WM_PAINT)

### 🧠 Architecture Style
- Modular component-based architecture
- Engine-driven design (Task Engine → Input Layer → Recorder → Player)
- Event-driven message loop (WinMain / WndProc)

### 🧪 Tooling
- VS Code (development environment)
- Git + GitHub (version control)
- Windows Terminal / PowerShell (build & run)

### 🚀 Optimization Focus
- Minimal binary size (~1MB target)
- No external dependencies
- Compile-time optimization (`-Os -s`)
- Native system calls only

---

## 🚀 Build Instructions

### Requirements
- MinGW-w64 (g++)
- Windows 10/11

### Build

```bash
build\build.bat
```

---

## ▶️ Run

```bash
.\taskr.exe
```

---

## 🏗️ Project Structure

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

## 🧠 Roadmap

### Phase 1 — UI Foundation ✔
- WinAPI window system
- Responsive rendering engine
- Basic UI layout system

### Phase 2 — Input Engine (Next)
- Keyboard hook system
- Mouse hook system
- Input event tracking

### Phase 3 — Automation Core
- Macro recording system
- Playback engine
- Timing accuracy system

### Phase 4 — Advanced Features
- Script engine
- UI controls (buttons, panels)
- Overlay mode
- Plugin architecture

👉 [Roadmap](docs/ROADMAP.md)

---

## 🚀 Status

- UI Foundation → Complete  
- Input Engine → In Progress  
- Recorder → Planned  
- Playback → Planned  
- Automation Core → Planned 

---

## 📜 License

This project is licensed under the MIT License.

## 📜 Code of Conduct

We keep communication respectful and focused:  
👉 [Code of Conduct](docs/CODE_OF_CONDUCT.md)