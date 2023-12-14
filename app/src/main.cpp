#include <iostream>

#include "../../core/include/GEngine.h"


void test_system1(geng::ECManager *ec_manager)
{
    geng::Entity new_ent = ec_manager->add_entity();
    ec_manager->add_component<uint32_t>(new_ent, 1u);
}

void test_system2(geng::ECManager *ec_manager)
{
    auto components = ec_manager->get_all_components<uint32_t>();
    if (components == nullptr) { return; }

    for (const auto component : *components)
    {
        LOG(component);
    }
}

int main()
{
    using namespace geng;
    GEngine engine;
    Scene scene;
    
    Entity entity1 = scene.ec_manager.add_entity();
    scene.ec_manager.add_component<PositionComponent>(entity1, PositionComponent{3.14159f});
    scene.add_custom_system(test_system2);
    scene.add_custom_system(test_system1);

    engine.run(&scene);

    return 0;
}