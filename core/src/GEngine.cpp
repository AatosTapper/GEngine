#include "../include/GEngine.h"

#include "../Runtime/Runtime.h"

#include <memory>

namespace geng
{
    static bool inited = false;

    GEngine::GEngine()
    {
        inited = true;
    }

    void GEngine::run(Scene *active_scene)
    {
        ASSERT(inited, "GEngine must be initialized before running.");
        ASSERT(active_scene->check_for_init(), "Scene must be initialized before running.");

        std::unique_ptr<Runtime> runtime = std::make_unique<Runtime>(active_scene);        
    }
}