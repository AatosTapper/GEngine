#include "TimerSystem.h"

namespace geng
{
    void timer_system_update(std::vector<TimerComponent> *components)
    {
        for (auto &timer : *components)
        {
            if (timer.length_ticks > 0u)
            {
                timer.status = TimerComponent::status::RUNNING;
            }
            else
            {
                timer.status = TimerComponent::status::WAITING;
            }
            if (timer.status == TimerComponent::status::RUNNING)
            {
                timer.length_ticks--;
                if (timer.length_ticks == 0u)
                {
                    timer.status = TimerComponent::status::DONE;
                }
            }
        }
    }

    std::string timer_status_str(const TimerComponent *timer)
    {
        switch (timer->status)
        {
        case TimerComponent::status::WAITING:
            return "WAITING";
        
        case TimerComponent::status::RUNNING:
            return "RUNNING";

        case TimerComponent::status::DONE:
            return "DONE";
    
        default:
            ERR("Undefined state for a timer component.");
            return "undefined state";
        }
    }
}