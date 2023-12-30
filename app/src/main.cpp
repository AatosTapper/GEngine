#include "../../core/include/GEngine.h"

using namespace geng;

GEngine engine;
Scene scene;

Entity player = scene.ec_manager.add_entity();
Entity oth_entity = scene.ec_manager.add_entity();
Entity another_entity = scene.ec_manager.add_entity();

void test_system(ECManager *ec_manager)
{
    TimerComponent *timer = ec_manager->get_component<TimerComponent>(player);
    LOG("Timer status: " << timer_status_str(timer) << " tick: " << timer->length_ticks);
}

int main()
{
    scene.ec_manager.add_component<TimerComponent>(player, TimerComponent(50));

    scene.ec_manager.add_component<RenderComponent>(another_entity, RenderComponent());
    scene.ec_manager.add_component<PositionComponent>(oth_entity, PositionComponent());
    scene.ec_manager.add_component<PositionComponent>(player, PositionComponent());
    scene.ec_manager.add_component<RenderComponent>(player, RenderComponent());
    scene.ec_manager.add_component<RenderComponent>(oth_entity, RenderComponent());
    scene.ec_manager.add_component<PositionComponent>(another_entity, PositionComponent());

    //scene.add_custom_system(test_system);

    engine.run(&scene);

    return 0;
}