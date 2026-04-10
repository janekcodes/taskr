@echo off
:: =====================================================
:: Taskr Build Script (MinGW-w64)
:: =====================================================
:: Purpose:
::  - Compile Taskr using g++
::  - Output optimized Windows GUI executable
::  - Keep build process simple and repeatable
:: =====================================================

echo =====================================
echo   Building Taskr (C++ / WinAPI)
echo =====================================

:: Always run from script directory
cd /d %~dp0

:: -----------------------------------------------------
:: Project Paths
:: -----------------------------------------------------
set SRC=..\src\main.cpp
set OUT=..\taskr.exe

:: -----------------------------------------------------
:: Compiler Settings
:: -----------------------------------------------------
:: -Os  -> optimize for size
:: -s   -> strip symbols (smaller exe)
:: -mwindows -> Windows GUI app (no console window)
:: -lgdi32 -> GDI rendering support
:: -----------------------------------------------------

echo [INFO] Compiling source...
echo [INFO] Source: %SRC%
echo [INFO] Output: %OUT%

g++ %SRC% -std=c++17 -Os -s -mwindows -lgdi32 -o %OUT%

:: -----------------------------------------------------
:: Build Result Handling
:: -----------------------------------------------------
if %errorlevel% == 0 (
    echo.
    echo =====================================
    echo   BUILD SUCCESSFUL
    echo   Output: taskr.exe
    echo =====================================
) else (
    echo.
    echo =====================================
    echo   BUILD FAILED
    echo   Check errors above
    echo =====================================
)

echo.
pause