# core

add_subdirectory(src)

target_link_libraries(core
    PRIVATE
    glfw
    GLEW::GLEW
    ${OPENGL_LIBRARIES}
    "-framework Cocoa"
    "-framework IOKit"
)

target_compile_options(core PRIVATE 
    -Wall
    -pedantic
    -std=c++17
)