#pragma once

#include "../Components/RenderComponent.h"
#include "../Components/PositionComponent.h"
#include "../Scene/Scene.h"

#include <iostream>
#include <vector>

struct GLFWwindow;

namespace geng
{
    struct RenderData
    {
        std::vector<RenderComponent> render_components;
        std::vector<PositionComponent> position_components;
        GLFWwindow *window = nullptr;
    };

    void sort_render_data(Scene *active_scene, RenderData *render_data);
}