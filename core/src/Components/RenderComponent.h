#pragma once

#include <stdint.h>
#include <memory>

namespace geng
{
    struct RenderComponent
    {
        std::shared_ptr<void> model;
        uint32_t *texture;
    };
}