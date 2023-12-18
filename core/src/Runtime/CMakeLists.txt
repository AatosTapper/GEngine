add_subdirectory(Threads)

add_library(Runtime Runtime.cpp Runtime.h)
target_include_directories(Runtime PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})