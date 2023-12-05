add_library(core STATIC GEngine.cpp)

add_subdirectory(Bruh)
target_link_libraries(core PRIVATE Bruh)