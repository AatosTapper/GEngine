#pragma once

#include <stdint.h>

namespace geng
{
    struct RenderComponent
    {
        float w, h;
        uint32_t *texture;
    };
}