#include <iostream>

#include "../../core/include/GEngine.h"

int main()
{
    geng::Scene *scene = new geng::Scene();
    geng::init();

    geng::scene_init(scene);
    geng::run(scene);

    delete scene;
    return 0;
}