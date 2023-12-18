#pragma once

#include "ThreadData.h"

#include <atomic>

namespace geng
{
    extern void logic_thread(RenderThreadData *render_thread_data, AudioThreadData *audio_thread_data, std::atomic<bool> &stop_threads);
}