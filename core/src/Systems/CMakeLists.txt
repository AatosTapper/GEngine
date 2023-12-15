add_library(PositionSystem PositionSystem.cpp PositionSystem.h)
target_include_directories(PositionSystem PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

add_library(TimerSystem TimerSystem.cpp TimerSystem.h)
target_include_directories(TimerSystem PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})