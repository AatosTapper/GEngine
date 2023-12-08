#include "../include/GEngine.h"

#include <iostream>

namespace geng
{
    void init()
    {
        LOG("Initializing GEngine");
        TRACK_PERFORMANCE("Init test", {
            // DO SOMETHING
        });
    }

    void run(Scene *active_scene)
    {
        // TODO: start three threads for rendering, audio and logic
        for (uint32_t i = 0; i < 20; i++)
        {
            scene_update(active_scene);
        }
    }
}