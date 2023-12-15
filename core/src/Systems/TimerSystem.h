#pragma once

#include "../Components/TimerComponent.h"

#include <vector>
#include <string>

namespace geng
{
    extern void timer_system_update(std::vector<TimerComponent> *components);
    extern std::string timer_status_str(const TimerComponent *timer);
}