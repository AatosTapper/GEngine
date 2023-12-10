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

        for (auto &system : custom_systems)
        {
            system.update(&ec_manager); // this is slow AF but can't think of any other way
        }
    }
}