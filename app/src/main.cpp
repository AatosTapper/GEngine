#include <iostream>

#include "../../core/include/GEngine.h"

int main()
{
    using namespace geng;
    GEngine engine;
    Scene scene;
    
    Entity entity1 = scene.ec_manager.add_entity();
    scene.ec_manager.add_component<PositionComponent>(entity1, PositionComponent{3.14159f});

    engine.run(&scene);

    return 0;
}