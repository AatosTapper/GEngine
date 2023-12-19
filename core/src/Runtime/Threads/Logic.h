#pragma once

#include "ThreadData.h"
#include "../../Scene/Scene.h"

#include <atomic>

namespace geng
{
    extern void logic_thread(Scene *active_scene, RenderThreadData *render_thread_data, AudioThreadData *audio_thread_data, std::atomic<bool> &stop_threads);
}