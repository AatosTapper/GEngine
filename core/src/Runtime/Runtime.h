#pragma once

#include "../Scene/Scene.h"
#include "../Renderer/Renderer.h"
#include "../Renderer/RenderData.h"

#include <memory>

namespace geng
{
    class Runtime
    {
    public:
        Runtime(Scene *active_scene);
        ~Runtime();

    private:
        std::unique_ptr<Renderer> m_renderer;

        void m_run_scene(Scene *active_scene);
    };
}