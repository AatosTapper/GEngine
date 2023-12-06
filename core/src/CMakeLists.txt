add_library(core STATIC GEngine.cpp)

add_subdirectory(Util)
target_link_libraries(core PRIVATE Util)