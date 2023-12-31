#include "Renderer.h"

#include "../Util/Util.h"

#include <GL/glew.h>
#include <GLFW/glfw3.h>

namespace geng
{
    void render_frame(RenderData *data)
    {
        glClear(GL_COLOR_BUFFER_BIT);

        glfwSwapBuffers(data->window);
        glfwPollEvents();
    }
}