#pragma once

#include "ThreadData.h"

#include <atomic>

namespace geng
{
    extern void audio_thread(AudioThreadData *audio_thread_data, std::atomic<bool> &stop_threads);
}