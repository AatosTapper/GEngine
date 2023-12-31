#include "RenderData.h"

#include "../ECS/ECS.h"
#include "../Util/Util.h"

namespace geng
{
    void sort_render_data(Scene *active_scene, RenderData *render_data)
    {
        const std::vector<RenderComponent> render_components = *active_scene->ec_manager.get_all_components<RenderComponent>();
        const std::vector<PositionComponent> position_components = *active_scene->ec_manager.get_all_components<PositionComponent>();
        std::vector<RenderComponent> render_components_sorted;
        std::vector<PositionComponent> position_components_sorted;
        
        uint32_t num_incorrect_entities = 0;
        for (const auto &ent : *active_scene->ec_manager.get_all_entities())
        {
            if (!active_scene->ec_manager.has_component<RenderComponent>(ent)) continue;

            int64_t render_index = active_scene->ec_manager.get_component_index<RenderComponent>(ent, true);
            int64_t position_index = active_scene->ec_manager.get_component_index<PositionComponent>(ent, true);
            if (render_index == -1 || position_index == -1)
            {
                num_incorrect_entities++;
                continue;
            }

            render_components_sorted.push_back(render_components[render_index]);
            position_components_sorted.push_back(position_components[position_index]);
        }

        ASSERT(!(num_incorrect_entities > 0), "[ " << num_incorrect_entities << " ] entities had insufficient components for rendering." 
        << "\n(doesn't count entities with no rendering component)");

        render_data->render_components = render_components_sorted;
        render_data->position_components = position_components_sorted;
    }
}