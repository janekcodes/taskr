# Taskr

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

## Navigation

- [Architecture](docs/ARCHITECTURE.md)
- [Contributing](docs/CONTRIBUTING.md)
- [Commit Convention](docs/COMMIT_CONVENTION.md)
- [Code of Conduct](docs/CODE_OF_CONDUCT.md)
- [License](LICENSE)

---

## Motivation

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

## Tech Stack

### Core Language
- C++ 

## Platform
- Windows API (WinAPI)
- GDI (Graphics Device Interface) for rendering
- User32 / Kernel32 system libraries

### Build System
- MinGW-w64 (GCC 15.x)
- Batch scripting (`build.bat`) for automation

### Tooling
- VS Code (development environment)
- Git + GitHub (version control)
- Windows Terminal / PowerShell (build & run)

---

## Build Instructions

### Requirements
- MinGW-w64 (g++)
- Windows 10/11

### Build

```bash
build\build.bat
```

---

## Run

```bash
.\taskr.exe
```

---

## Project Structure

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

## Status

- UI Foundation → Complete  
- Input Engine → In Progress  
- Recorder → Planned  
- Playback → Planned  
- Automation Core → Planned 

---

## License

This project is licensed under the MIT License.

## Code of Conduct

We keep communication respectful and focused:  
[Code of Conduct](docs/CODE_OF_CONDUCT.md)