# app

add_subdirectory(src)

target_link_libraries(main PRIVATE core)

target_compile_options(main PRIVATE 
    -Wall
    -pedantic
    -std=c++17
)
