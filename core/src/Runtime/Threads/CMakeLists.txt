add_library(Logic Logic.cpp Logic.h)
target_include_directories(Logic PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

add_library(Render Render.cpp Render.h)
target_include_directories(Render PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

add_library(Audio Audio.cpp Audio.h)
target_include_directories(Audio PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

add_library(ThreadData ThreadData.cpp ThreadData.h)
target_include_directories(ThreadData PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})