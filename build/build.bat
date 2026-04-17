@echo off
:: =====================================================
:: Taskr Build Script (MinGW-w64)
:: =====================================================

echo =====================================
echo   Building Taskr (C++ / WinAPI)
echo =====================================

cd /d %~dp0

:: -----------------------------------------------------
:: Output
:: -----------------------------------------------------
set OUT=..\taskr.exe

:: -----------------------------------------------------
:: Source Files (ALL CPP FILES)
:: -----------------------------------------------------
set SOURCES=^
..\src\main.cpp ^
..\src\core\engine\task_engine.cpp ^
..\src\utils\time.cpp ^
..\src\core\input\keyboard.cpp ^
..\src\core\input\mouse.cpp ^
..\src\core\recorder\recorder.cpp ^
..\src\core\player\player.cpp

:: -----------------------------------------------------
:: Build
:: -----------------------------------------------------

echo [INFO] Compiling project...

g++ %SOURCES% -std=c++17 -Os -s -mwindows -lgdi32 -o %OUT%

:: -----------------------------------------------------
:: Result
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
    echo =====================================
)

echo.
pause