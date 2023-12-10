#pragma once

#include "../ECS/ECS.h"
#include "../Systems/Systems.h"

#include <vector>

namespace geng
{
    class Scene
    {
    public:
        Scene();

        ECManager ec_manager;
        std::vector<CustomSystem> custom_systems;

        void update();
        bool check_for_init();

    private:
        void m_update_systems();
    };
}