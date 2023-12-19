#include "Logic.h"

#include "../../Util/Util.h"
#include "../../Components/TimerComponent.h"

#include <chrono>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <atomic>

namespace geng
{
    static void change_render_data(RenderThreadData *render_thread_data, Scene *active_scene)
    {
        {            
            std::unique_lock<std::mutex> render_lock(render_thread_data->mutex);
            
            // Copy the needed components to the render engine
            render_thread_data->data = { 
                *active_scene->ec_manager.get_all_entities(),
                *active_scene->ec_manager.get_all_components<RenderComponent>(), 
                *active_scene->ec_manager.get_all_components<PositionComponent>() 
            };

            render_thread_data->data_changed = true;
        }
        render_thread_data->cv.notify_one();
    }

    static void change_audio_data(AudioThreadData *audio_thread_data, Scene *active_scene)
    {
        {
            std::unique_lock<std::mutex> audio_lock(audio_thread_data->mutex);

            // Change data here
            
            audio_thread_data->data_changed = true;
        }
        audio_thread_data->cv.notify_one();
    }

    void logic_thread(Scene *active_scene, RenderThreadData *render_thread_data, AudioThreadData *audio_thread_data, std::atomic<bool> &stop_threads)
    {
        THREAD_LOG_STR("Logic Thread Run");
        while (!stop_threads)
        {
            // TODO: gameloop with glfw windowing

            active_scene->update();

            //std::this_thread::sleep_for(std::chrono::milliseconds(16));

            if (active_scene->ec_manager.get_component<TimerComponent>(Entity{0, 0})->status == TimerComponent::status::DONE)
            {
                audio_thread_data->stop_thread = true;
                render_thread_data->stop_thread = true;
                stop_threads = true;

                audio_thread_data->cv.notify_one();
                render_thread_data->cv.notify_one();
                break;
            }

            change_render_data(render_thread_data, active_scene);
            change_audio_data(audio_thread_data, active_scene);
        }
    }
}