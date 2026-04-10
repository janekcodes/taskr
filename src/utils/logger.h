#pragma once
#include <string>

/*
=========================================================
 Logger Module (Taskr)
=========================================================

Location:
    src/core/utils/

Responsibility:
    Handles debug / info / error logging.

Future Role:
    - Print structured logs
    - Help debugging engine systems
    - Optionally write logs to file
=========================================================
*/

enum class LogLevel {
    Info,
    Warning,
    Error
};

class Logger {
public:
    static void log(const std::string& message, LogLevel level = LogLevel::Info);

private:
    static std::string getPrefix(LogLevel level);
};