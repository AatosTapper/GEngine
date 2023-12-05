add_executable(main main.cpp)

add_subdirectory(Test)
target_link_libraries(main PRIVATE Test)