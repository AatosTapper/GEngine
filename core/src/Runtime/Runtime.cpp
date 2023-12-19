#include "Runtime.h"

#include "Threads/Logic.h"
#include "Threads/Render.h"
#include "Threads/Audio.h"

#include <thread>
#include <mutex>
#include <condition_variable>
#include <atomic>

namespace geng
{
    Runtime::Runtime(Scene *active_scene)
    {
        RenderThreadData render_thread_data;
        AudioThreadData audio_thread_data;
        std::atomic<bool> stop_threads(false);

        m_init_thread_data(active_scene, &render_thread_data, &audio_thread_data);

        std::thread logic([&] { logic_thread(active_scene, &render_thread_data, &audio_thread_data, stop_threads); });
        std::thread render([&] { render_thread(&render_thread_data, stop_threads); });
        std::thread audio([&] { audio_thread(&audio_thread_data, stop_threads); });

        logic.join();
        render.join();
        audio.join();
    }

    Runtime::~Runtime()
    {
        
    }

    void Runtime::m_init_thread_data(Scene *active_scene, RenderThreadData *render_thread_data, AudioThreadData *audio_thread_data)
    {
        render_thread_data->data = { 
            *active_scene->ec_manager.get_all_entities(),
            *active_scene->ec_manager.get_all_components<RenderComponent>(), 
            *active_scene->ec_manager.get_all_components<PositionComponent>() 
        };

        render_thread_data->data_changed = false;
        render_thread_data->stop_thread = false;

        audio_thread_data->data = {0};
        audio_thread_data->data_changed = false;
        audio_thread_data->stop_thread = false;
    }
}