#pragma once

#include <iostream>
#include <chrono>

#define LOG(a) std::cout << "Log: " << a << "\n";

#define ERR(message) \
    std::cerr << "Error: " << message \
    << "\n  File: " << __FILE__ \
    <<  "\n  Function: " << __FUNCTION__ \
    << "\n  Line: " << __LINE__ << "\n"

#define WARN(message) \
    std::cerr << "Warning: " << message \
    << "\n  File: " << __FILE__ \
    << "\n  Function: " << __FUNCTION__ \
    << "\n  Line: " << __LINE__ << "\n"

#define INFO(message) \
    std::cout << "Info: " << message \
    << "\n  File: " << __FILE__ \
    << "\n  Function: " << __FUNCTION__ \
    << "\n  Line: " << __LINE__ << "\n"

#define ASSERT(condition, message) \
    do { \
        if (!(condition)) { \
            ERR("Assertion failed: " << message); \
            std::terminate(); \
        } \
    } while (0)

#define TRACK_PERFORMANCE(message, code) \
    do { \
        auto start = std::chrono::high_resolution_clock::now(); \
        code; \
        auto end = std::chrono::high_resolution_clock::now(); \
        auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start).count(); \
        INFO(message << " - Duration: " << duration << " microseconds"); \
    } while (0)

namespace GEng
{
    
}

