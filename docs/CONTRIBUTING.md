# 🤝 Contributing Guide

Welcome to **Taskr**, a native Windows automation engine built in C++.

This guide explains how to contribute in a clean, structured, and consistent way.

Even though this is currently a solo project, contributions are welcome and will be reviewed carefully to maintain quality and long-term architecture.

---

## 📌 Overview

Before contributing:

- Read this document fully  
- Understand the project structure and goals  
- Keep changes aligned with the core vision of Taskr (simplicity, performance, native Windows design)  

---

## 🧠 Project Philosophy

Taskr is built around a few core principles:

- Keep it **lightweight and fast**
- Avoid unnecessary complexity
- Stay **fully native (no external runtimes)**
- Prefer clarity over abstraction
- Maintain a modular architecture

Any contribution should respect these principles.

---

## 🚀 Step-by-Step Contribution Process

### Step 1 — Fork the Repository

- Go to the GitHub repository  
- Click **Fork** (top right)  
- This creates your own copy of Taskr  

---

### Step 2 — Clone Your Fork

```bash
git clone https://github.com/YOUR-USERNAME/taskr.git
cd taskr
```

---

### Step 3 — Add Upstream Remote

```bash
git remote add upstream https://github.com/janekcodes/taskr.git
git remote -v
```

---

### Step 4 — Sync with Latest Changes

Always start from the latest version:

```bash
git fetch upstream
git checkout main
git rebase upstream/main
```

---

### Step 5 — Create a Feature Branch

Never work directly on `main`.

```bash
git checkout -b feature/your-feature-name
```

### Branch Naming Examples

- feature/input-system  
- feature/mouse-hook  
- fix/window-render-bug  
- refactor/core-engine  

---

### Step 6 — Make Your Changes

While developing:

- Keep changes focused and minimal  
- Follow existing project structure  
- Avoid mixing unrelated changes in one branch  
- Keep code readable and modular  

---

### Step 7 — Build & Test

Before committing:

- Ensure project builds successfully  
- Run the `.bat` build script  
- Confirm no runtime or compile errors  
- Test UI rendering and input behavior if affected  

---

### Step 8 — Commit Changes

Use **Conventional Commits**:

```bash
git add .
git commit -m "feat: add input capture system"
```

### Commit Types

- `feat:` new feature  
- `fix:` bug fix  
- `refactor:` code restructuring (no behavior change)  
- `docs:` documentation updates  
- `chore:` build/system changes  
- `test:` testing changes  

---

### Step 9 — Push Your Branch

```bash
git push origin feature/your-feature-name
```

---

### Step 10 — Open a Pull Request

On GitHub:

1. Go to your fork  
2. Click **Compare & Pull Request**  
3. Target: `main` branch  
4. Add a clear description  

Include:

- What you changed  
- Why you changed it  
- Any design decisions  
- Screenshots (if UI-related)  

---

## 🔄 Keeping Your Fork Updated

If the main project updates:

```bash
git checkout main
git fetch upstream
git rebase upstream/main
git push origin main

git checkout feature/your-feature-name
git rebase main
```

---

## 🧪 Code Guidelines

To keep Taskr clean and maintainable:

- Prefer clarity over clever code  
- Avoid unnecessary dependencies  
- Keep modules separated by responsibility  
- Use consistent naming conventions  
- Comment only when logic is non-obvious  

---

## 📂 Project Structure Awareness

Before contributing, understand the architecture:

- `core/` → engine, input, recorder, player  
- `platform/` → Windows-specific implementation  
- `utils/` → helpers and shared utilities  
- `main.cpp` → application entry point  

---

## ⚠️ Important Rules

- Do NOT break core architecture design  
- Do NOT introduce external dependencies  
- Do NOT commit large unrelated changes  
- Keep PRs small and focused  

---

## 📜 Commit Style Examples

```text
feat: add keyboard hook system
fix: resolve window resize rendering bug
refactor: simplify input pipeline
docs: update roadmap
chore: improve build script
```

---

## 🚀 Final Note

Even though Taskr is still early in development, the goal is to keep the codebase clean and scalable from the beginning.

Every contribution should move the project closer to a **fast, minimal, native automation engine for Windows**.