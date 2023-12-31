#pragma once

#include "../Scene/Scene.h"
#include "../Renderer/RenderData.h"

namespace geng
{
    class Runtime
    {
    public:
        Runtime(Scene *active_scene);
        ~Runtime();
    };
}