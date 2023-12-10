#include "../include/GEngine.h"

#include <iostream>

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

        // TODO: start three threads for rendering, audio and logic
        for (uint32_t i = 0; i < 10; i++)
        {
            active_scene->update();
        }
    }
}