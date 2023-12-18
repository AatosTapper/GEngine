#pragma once

#include "ThreadData.h"

#include <atomic>

namespace geng
{
    extern void render_thread(RenderThreadData *render_thread_data, std::atomic<bool> &stop_threads);
}