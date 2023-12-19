#pragma once

#include <iostream>
#include <stdio.h>
#include <chrono>

#ifndef SILENCE_TEXT

#define LOG(a) std::cout << "Log: " << a << "\n";

// Ensure that text doesn't get messed up by other threads
#define THREAD_LOG_STR(a) printf("Log: %s\n", a)
#define THREAD_LOG_INT(a) printf("Log: %d\n", a)
#define THREAD_LOG_FLO(a) printf("Log: %f\n", a)

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

#else

#define LOG(a) 
#define THREAD_LOG_STR(a)
#define THREAD_LOG_INT(a)
#define THREAD_LOG_FLO(a)
#define ERR(message)
#define WARN(message)
#define INFO(message)
#define ASSERT(condition, message)
#define TRACK_PERFORMANCE(message, code)

#endif

namespace geng
{

}

