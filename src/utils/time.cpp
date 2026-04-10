#include "time.h"
#include <chrono>
#include <ctime>

/*
=========================================================
 Time Implementation (Skeleton)
=========================================================
*/

long long Time::nowMillis() {
    using namespace std::chrono;

    return duration_cast<milliseconds>(
        system_clock::now().time_since_epoch()
    ).count();
}

std::string Time::nowString() {
    std::time_t t = std::time(nullptr);
    char buffer[64];

    std::strftime(buffer, sizeof(buffer),
                  "%Y-%m-%d %H:%M:%S",
                  std::localtime(&t));

    return std::string(buffer);
}