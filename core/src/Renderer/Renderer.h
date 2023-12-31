#pragma once

#include "RenderData.h"

#define MAX_TRIS 4096
#define MAX_VERT MAX_TRIS * 3

struct GLFWwindow;

namespace geng
{
    class Renderer
    {
    public:
        Renderer();
        ~Renderer();

        void render_frame(RenderData *data);
        bool get_window_should_close();
    
    private:
        GLFWwindow *m_window;
        uint32_t m_vao;
        uint32_t m_vbo;
        bool m_window_should_close;
    };
}