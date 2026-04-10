# 🧾 Commit Convention

This document defines the commit style used in Taskr.

Even though this is currently a solo project, I use a strict commit format to keep the history clean, readable, and scalable as the project grows.

---

## 📌 Core Principle

Every commit should represent a **single, clear change**.

No mixing features, fixes, or unrelated edits in one commit.

---

## 🧠 Format

All commits follow this structure:

```
type: short description
```

Example:

```
feat: add input hook system
```

---

## 🏷️ Commit Types

### ✨ Features
```
feat: add new functionality
```
Used for new systems or major additions.

Examples:
- feat: add keyboard input capture
- feat: implement recorder system

---

### 🐛 Fixes
```
fix: resolve issue or bug
```

Examples:
- fix: correct window resize rendering bug
- fix: resolve input lag in event loop

---

### 🔄 Refactoring
```
refactor: restructure code without changing behavior
```

Examples:
- refactor: simplify input pipeline
- refactor: clean up core engine structure

---

### 📚 Documentation
```
docs: update documentation
```

Examples:
- docs: update roadmap
- docs: improve architecture explanation

---

### 🧹 Chores
```
chore: maintenance or build system changes
```

Examples:
- chore: update build script
- chore: improve compilation flags

---

### 🧪 Tests
```
test: add or update tests
```

Examples:
- test: validate input system behavior

---

## 📌 Rules

- Commit messages must be lowercase
- Keep messages short and meaningful
- One logical change per commit
- Do not commit unfinished features
- Do not mix multiple types in one commit
- Avoid vague messages like "update code" or "fix stuff"

---

## 🧠 Good Examples

```
feat: add mouse input capture
fix: resolve window flicker on resize
refactor: simplify core engine loop
docs: update architecture overview
chore: improve build optimization
```

---

## 🚫 Bad Examples

```
update stuff
fixed things
new changes
final version
wip
```

These reduce clarity and should not be used.

---

## 🚀 Why This Matters

Taskr is a system-level project, and commit history is part of the design.

A clean history helps with:

- debugging
- long-term maintainability
- understanding system evolution
- professional presentation (GitHub + recruiters)

---

## 🧠 Final Note

Even though this is a personal project, I treat commits like part of the engineering process.

Each commit should clearly describe *what changed and why*, not just that something changed.