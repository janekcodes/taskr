# Taskr

A fast, lightweight Windows automation tool for repetitive tasks: clicking, typing, and mouse movement.

> ⚠️ **Status: early development.** Taskr is being built from scratch. Features below are planned unless checked.

## Features

- [ ] **Auto-clicker**: click at a set interval, start/stop with a hotkey
- [ ] **Text typing**: type a saved string or key sequence on a hotkey
- [ ] **Record & replay**: capture mouse and keyboard input and play it back
- [ ] **Simple GUI**: native window showing status and controls

## Why Taskr?

Most Windows automation tools are either too heavy for simple tasks, hard to set up, or depend on scripting runtimes. Taskr is a single native executable written in modern C++ with the Windows API: no installer required, no runtime, no dependencies.

## Tech Stack

- C++20
- Windows API (Win32)
- CMake + MSVC (Visual Studio Build Tools)

## Building

**Requirements**

- Windows 10 or 11
- [Visual Studio Build Tools](https://visualstudio.microsoft.com/downloads/) with the **Desktop development with C++** workload
- [CMake](https://cmake.org/) 3.25+

**Build and run**

```powershell
cmake --preset windows-msvc
cmake --build --preset release
.\build\Release\taskr.exe
```

## Responsible Use

Taskr is built for productivity and accessibility. Many online games and services prohibit automated input. Check their rules before using Taskr with them. Taskr does not attempt to bypass anti-cheat or security software.

## License

[MIT](LICENSE)