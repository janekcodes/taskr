#include "logger.h"
#include <iostream>

/*
=========================================================
 Logger Implementation (Skeleton)
=========================================================
*/

void Logger::log(const std::string& message, LogLevel level) {
    std::cout << getPrefix(level) << message << std::endl;
}

std::string Logger::getPrefix(LogLevel level) {
    switch (level) {
        case LogLevel::Info:    return "[INFO] ";
        case LogLevel::Warning: return "[WARN] ";
        case LogLevel::Error:   return "[ERROR] ";
        default:                return "[LOG] ";
    }
}