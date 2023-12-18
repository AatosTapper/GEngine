#pragma once

#include "../Scene/Scene.h"
#include "Threads/ThreadData.h"

namespace geng
{
    class Runtime
    {
    public:
        Runtime(Scene *active_scene);
        ~Runtime();

    private:
        void m_init_thread_data(Scene *active_scene, RenderThreadData *render_thread_data, AudioThreadData *audio_thread_data);
    };
}