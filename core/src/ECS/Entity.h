#pragma once

#include <stdint.h>

namespace geng
{
    // Type can be some user defined enum for example.
    // It can't be changed afterwards.
    struct Entity
    {
        uint32_t id;
        uint32_t type; 
    };
}