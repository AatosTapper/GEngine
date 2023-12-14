#include "Scene.h"

#include "../Util/Util.h"
#include "../Components/Components.h"

#include <string>

namespace geng
{
    static bool scene_initialized = false;

    Scene::Scene()
    {
        scene_initialized = true;
    }

    void Scene::add_custom_system(void (*func)(ECManager*))
    {
        m_custom_systems.push_back(func);
    }

    void Scene::update()
    {
        m_update_systems();
    }

    bool Scene::check_for_init()
    {
        return scene_initialized;
    }

    void Scene::m_update_systems()
    {
        position_system_update(ec_manager.get_all_components<PositionComponent>());

        for (auto system : m_custom_systems)
        {
            system(&ec_manager);
        }
    }
}