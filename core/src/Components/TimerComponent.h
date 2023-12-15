#pragma once

#include "../Util/Util.h"

#include <stdint.h>

namespace geng
{
    struct TimerComponent
    {
        TimerComponent(uint32_t lenght_ticks_) : 
            length_ticks(lenght_ticks_), 
            status(status::WAITING) {}

        uint32_t length_ticks;
        enum class status 
        {
            WAITING = 0u,
            RUNNING = 1u,
            DONE = 2u
        } status;
    };
}