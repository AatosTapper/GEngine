#pragma once

#include "../../Components/RenderComponent.h"
#include "../../Components/PositionComponent.h"
#include "../../ECS/Entity.h"

#include <iostream>
#include <mutex>
#include <condition_variable>
#include <atomic>
#include <vector>

namespace geng
{
    struct AudioData
    {
        uint32_t some_data;
    };

    struct RenderData
    {
        std::vector<Entity> entities;
        std::vector<RenderComponent> render_components;
        std::vector<PositionComponent> position_components;
    };

    struct AudioThreadData
    {
        std::mutex mutex;
        std::condition_variable cv;
        std::atomic_bool stop_thread;
        AudioData data;
        bool data_changed;
    };

    struct RenderThreadData
    {
        std::mutex mutex;
        std::condition_variable cv;
        std::atomic_bool stop_thread;
        RenderData data;
        bool data_changed;
    };
}