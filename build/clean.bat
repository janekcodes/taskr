@echo off
:: =====================================================
:: Taskr Clean Script (MinGW-w64)
:: =====================================================
:: Purpose:
::  - Remove compiled binaries and build artifacts
::  - Reset project to a clean state
::  - Useful before fresh builds or commits
:: =====================================================

echo =====================================
echo   Cleaning Taskr Build Files
echo =====================================

cd /d %~dp0

:: -----------------------------------------------------
:: Remove compiled executable
:: -----------------------------------------------------
if exist ..\taskr.exe (
    del ..\taskr.exe
    echo [OK] Removed taskr.exe
) else (
    echo [INFO] No executable found
)

:: -----------------------------------------------------
:: Remove common build artifacts (if they exist)
:: -----------------------------------------------------
del /q ..\*.o 2>nul
del /q ..\*.obj 2>nul
del /q ..\*.pdb 2>nul
del /q ..\*.ilk 2>nul

echo.
echo =====================================
echo   CLEAN COMPLETE
echo =====================================

pause