#pragma once

#include "../Components/PositionComponent.h"

#include <vector>

namespace geng
{
    extern void position_system_update(std::vector<PositionComponent> *components);
}