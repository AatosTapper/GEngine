#pragma once

#include "RenderData.h"

#include "../../dep/glm/glm.hpp"

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
        glm::mat4 m_projection;
        uint32_t m_vao;
        uint32_t m_vbo;
        uint32_t m_tri_count;
        bool m_window_should_close;
    };
}