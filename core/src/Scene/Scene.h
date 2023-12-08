#pragma once

#include "../ECS/ECS.h"

namespace geng
{
    typedef struct Scene
    {
        ECManager ec_manager;
    }
    Scene;

    extern void scene_init(Scene *scene);
    extern void scene_update(Scene *scene);
}