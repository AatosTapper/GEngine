#pragma once

#include "../ECS/ECS.h"

namespace geng
{
    class CustomSystem
    {
    public:
        virtual ~CustomSystem() = default;
        virtual void update(ECManager *ec_manager) = 0;
    };
}