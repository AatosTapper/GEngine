#include <iostream>

#include "../../core/include/GEngine.h"

void test_system1(geng::ECManager *ec_manager)
{
    auto components = ec_manager->get_all_components<geng::PositionComponent>();
    for (const auto &component : *components)
    {
        LOG(component.placeholder_data);
    }
}

void test_system2(geng::ECManager *ec_manager)
{
    auto components = ec_manager->get_all_components<geng::PositionComponent>();
    for (const auto &component : *components)
    {
        LOG(component.placeholder_data * 2);
    }
}

int main()
{
    using namespace geng;
    GEngine engine;
    Scene scene;
    
    Entity entity1 = scene.ec_manager.add_entity();
    scene.ec_manager.add_component<PositionComponent>(entity1, PositionComponent{3.14159f});
    scene.add_custom_system(test_system1);
    scene.add_custom_system(test_system2);

    engine.run(&scene);

    return 0;
}