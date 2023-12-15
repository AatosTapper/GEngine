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

    if (timer->status == TimerComponent::status::WAITING)
    {
        LOG("New timer started.");
        timer->length_ticks = 7;
    }
}

int main()
{
    scene.ec_manager.add_component<TimerComponent>(player, TimerComponent(2));
    scene.add_custom_system(test_system);

    engine.run(&scene);

    return 0;
}