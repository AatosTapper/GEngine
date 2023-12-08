#pragma once

#include "../src/Util/Util.h"
#include "../src/Scene/Scene.h"
#include "../src/ECS/ECS.h"

namespace geng
{
    extern void init();
    extern void run(Scene *active_scene);
}