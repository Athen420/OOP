#include "Timer.h"

namespace sdds
{
    // Start the timer by capturing the current time
    void Timer::start() {
        startTime = std::chrono::steady_clock::now();
    }

    // Stop the timer and calculate the elapsed time in nanoseconds
    long long Timer::stop() {
        std::chrono::time_point<std::chrono::steady_clock> now = std::chrono::steady_clock::now();
        return std::chrono::duration_cast<std::chrono::nanoseconds>(now - startTime).count();
    }
} // namespace sdds
