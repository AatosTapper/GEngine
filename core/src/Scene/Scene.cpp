#include "Scene.h"

#include "../Util/Util.h"
#include "../Components/Components.h"

#include <string>

namespace geng
{
    static bool scene_initialized = false;
    static bool is_first_update = true;

    Scene::Scene()
    {
        Entity e1 = ec_manager.add_entity();

        ec_manager.add_component<PositionComponent>(e1, PositionComponent(1));
        ec_manager.add_component<float>(e1, 1.0f);
        ec_manager.add_component<std::string>(e1, "bruh");

        scene_initialized = true;
    }

    void Scene::update()
    {
        m_update_systems();

        if (is_first_update)
        {
            ec_manager.remove_component<PositionComponent>(Entity{0, 0});
            ec_manager.remove_component<float>(Entity{0, 0});
            ec_manager.remove_component<std::string>(Entity{0, 0});
            ec_manager.remove_entity(Entity{0, 0});

            is_first_update = false;
        }   
    }

    bool Scene::check_for_init()
    {
        return scene_initialized;
    }

    void Scene::m_update_systems()
    {
        auto position_components = ec_manager.get_all_components<PositionComponent>();
        position_system_update(position_components);

        for (auto &system : custom_systems)
        {
            system.update(&ec_manager); // this is slow AF but can't think of any other way
        }
    }
}