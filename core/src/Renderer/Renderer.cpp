#include "Renderer.h"

#include "../Util/Util.h"

#include <GL/glew.h>
#include <GLFW/glfw3.h>

namespace geng
{
    Renderer::Renderer() : m_window_should_close(false)
    {

    }

    Renderer::~Renderer()
    {

    }

    void Renderer::render_frame(RenderData *data)
    {
        glClear(GL_COLOR_BUFFER_BIT);

        glfwSwapBuffers(m_window);
        glfwPollEvents();
    }

    bool Renderer::get_window_should_close()
    {
        return m_window_should_close;
    }
}