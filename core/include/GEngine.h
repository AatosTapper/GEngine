#pragma once

#include "../src/Util/Util.h"
#include "../src/Scene/Scene.h"
#include "../src/ECS/ECS.h"
#include "../src/Components/Components.h"
#include "../src/Systems/Systems.h"

namespace geng
{
    class GEngine
    {
    public:
        GEngine();
        void run(Scene *active_scene);
    };
}