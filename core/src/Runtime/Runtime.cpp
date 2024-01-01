#include "Runtime.h"

namespace geng
{
    Runtime::Runtime(Scene *active_scene)
    {
        m_renderer = std::make_unique<Renderer>();

        m_run_scene(active_scene);
    }

    Runtime::~Runtime()
    {
        
    }

    void Runtime::m_run_scene(Scene *active_scene)
    {
        RenderData render_data;

        while(!m_renderer->get_window_should_close())
        {
            sort_render_data(active_scene, &render_data);
            //m_renderer->render_frame(&render_data);
            WARN("Renderer is commented out in the gameloop");
        }
    }
}