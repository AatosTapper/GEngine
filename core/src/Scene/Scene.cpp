#include "Scene.h"

#include "../Util/Util.h"
#include "../Components/Components.h"

namespace geng
{
    void scene_init(Scene *scene)
    {
        ASSERT(scene, "Can't init a null scene.");

        Entity e1 = scene->ec_manager.add_entity();
        Entity e2 = scene->ec_manager.add_entity();
        Entity e3 = scene->ec_manager.add_entity();
        Entity e4 = scene->ec_manager.add_entity();
        scene->ec_manager.add_component<PositionComponent>(e1, PositionComponent(1));
        scene->ec_manager.add_component<PositionComponent>(e2, PositionComponent(2));
        scene->ec_manager.add_component<PositionComponent>(e3, PositionComponent(3));
        scene->ec_manager.add_component<PositionComponent>(e4, PositionComponent(4));
    }

    void scene_update(Scene *scene)
    {
        auto position_components = scene->ec_manager.get_all_components<PositionComponent>();
        position_update(position_components);
    }
}