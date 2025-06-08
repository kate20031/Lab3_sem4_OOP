#pragma once
#include <chrono>

class Timer {
public:
    Timer() { start = std::chrono::high_resolution_clock::now(); }

    void reset() {
        start = std::chrono::high_resolution_clock::now();
    }

    double elapsed() const {
        auto end = std::chrono::high_resolution_clock::now();
        return std::chrono::duration<double, std::milli>(end - start).count();
    }

private:
    std::chrono::high_resolution_clock::time_point start;
};
