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
        
        void add_custom_system(void (*func)(ECManager*));
        void update();
        bool check_for_init();

    private:
        std::vector<void (*)(ECManager*)> m_custom_systems;

        void m_update_systems();
    };
}