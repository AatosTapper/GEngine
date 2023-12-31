add_library(core STATIC GEngine.cpp)

add_subdirectory(Util)
target_link_libraries(core PRIVATE Util)

add_subdirectory(Scene)
target_link_libraries(core PRIVATE Scene)

add_subdirectory(Systems)
target_link_libraries(core PRIVATE PositionSystem)
target_link_libraries(core PRIVATE TimerSystem)

add_subdirectory(Runtime)
target_link_libraries(core PRIVATE Runtime)

add_subdirectory(Renderer)
target_link_libraries(core PRIVATE Renderer)
target_link_libraries(core PRIVATE RenderData)