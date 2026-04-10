# 🧠 Taskr Roadmap

This roadmap reflects how Taskr is actually being built — starting from my own frustration with existing tools, and evolving step by step into a native Windows automation engine.

It’s not a corporate plan. It’s a real progression of what I’m building and why.

---

## 📌 How This Started

As I started using different automation tools on Windows, I kept running into the same frustrations.

Most tools I tried were either:
- too heavy for simple tasks  
- overly complicated to set up or understand  
- dependent on external runtimes or scripting environments  
- or limited in how much control I actually had over the system  

At some point, I realized I wasn’t just looking for “another tool” — I was trying to find something that felt simple, fast, and fully under my control.

That’s what led me to start building Taskr.

The idea was simple: build a minimal, native Windows automation engine in C++ that makes repetitive tasks easier without unnecessary complexity.

This roadmap follows how that idea is turning into a real system.

---

## 🧱 Phase 1 — UI Foundation (Completed)

This is where everything started.

✔ Native WinAPI window setup  
✔ Basic GDI rendering system  
✔ Resizable window behavior  
✔ Simple centered UI text  
✔ Basic build system (MinGW-w64)  

### What this phase gave me
A working native Windows application with no external dependencies — just C++ and the Windows API.

This proved the idea was actually possible.

---

## ⌨️ Phase 2 — Input Engine (Current Focus)

Right now, Taskr is only a visual foundation — it doesn’t yet understand input in a structured way.

This is the most important phase so far.

I’m currently building:
- low-level keyboard hooks  
- mouse input capture  
- structured input event system  
- timing between actions  
- a consistent internal representation of user behavior  

### Why this matters
Everything depends on this layer.

Without reliable input capture, there is no recording, playback, or automation. This is the core of the entire project.

---

## 🎥 Phase 3 — Recording System

Once input is stable, I’ll start building a recording system.

This will allow Taskr to:
- record real user actions  
- store them as structured events  
- manage start/stop recording sessions  
- preserve accurate timing between inputs  

The goal is to turn real user behavior into something that can be replayed and reused.

---

## ▶️ Phase 4 — Playback Engine

After recording works, I’ll move into playback.

This will include:
- replaying recorded input sequences  
- maintaining precise timing  
- basic controls (start, stop, pause)  
- optional looping  

At this stage, Taskr becomes a working macro automation tool.

---

## ⚙️ Phase 5 — Automation Core

This is where the project starts becoming more than just recording and replaying.

The goal here is to move toward actual automation logic:
- chaining actions together  
- executing tasks automatically  
- adding structured behavior over time  
- exploring simple rule-based automation  

This phase is still evolving as I build toward it.

---

## 🧩 Phase 6 — Interface & Control Layer

Once the engine is stable, I’ll improve usability:

- interactive UI controls (buttons, status, panels)  
- hotkey system  
- better layout system  
- multiple profiles or sessions  

The goal is to make Taskr usable without needing to think about the internals.

---

## 🚀 Phase 7 — Optimization & Polish

After everything works, I’ll focus on refinement:

- reducing binary size (~1MB target)  
- improving performance  
- cleaning architecture and modules  
- improving stability and responsiveness  

---

## 🧠 Long-Term Vision

I’m not trying to over-engineer this project.

The goal with Taskr is simple:

> build a lightweight, native Windows automation engine that stays fast, minimal, and fully under user control.

I want it to feel like something that removes friction — not something that adds complexity.

---

## 📌 Current Status

Right now, I’m focused entirely on Phase 2 — the input engine.

Everything else depends on this layer being solid, so I’m taking my time to build it properly before moving forward.

---

## 🚀 Status Overview

- UI Foundation → Completed  
- Input Engine → In Progress  
- Recording System → Planned  
- Playback Engine → Planned  
- Automation Core → Planned  
- Interface Layer → Planned  
- Optimization → Planned  