# core

add_subdirectory(src)

target_compile_options(core PRIVATE 
    -Wall
    -pedantic
    -std=c++17
)