add_library(Renderer Renderer.cpp Renderer.h)
target_link_libraries(Renderer
    PRIVATE
    glfw
    GLEW::GLEW
    ${OPENGL_LIBRARIES}
    "-framework Cocoa"
    "-framework IOKit"
)
target_include_directories(Renderer PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

add_library(RenderData RenderData.cpp RenderData.h)
target_include_directories(RenderData PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})