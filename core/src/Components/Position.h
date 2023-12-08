#pragma once

#include <vector>

namespace geng
{
    typedef struct PositionComponent
    {
        PositionComponent(float data);
        
        float placeholder_data;
    }
    PositionComponent;

    extern void position_update(std::vector<PositionComponent> *components);
}