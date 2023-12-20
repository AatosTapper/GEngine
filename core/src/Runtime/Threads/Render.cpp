#include "Render.h"

#include "../../Util/Util.h"

#include <thread>
#include <mutex>
#include <condition_variable>
#include <atomic>

namespace geng
{
    static void render(RenderData *data)
    {
        //THREAD_LOG_STR("Rendering");
    }

    void render_thread(RenderThreadData *render_thread_data, std::atomic<bool> &stop_threads)
    {
        while (!render_thread_data->stop_thread)
        {
            std::unique_lock<std::mutex> lock(render_thread_data->mutex);
            render_thread_data->cv.wait(lock, [&] { return render_thread_data->data_changed || stop_threads; });

            if (!stop_threads)
            {
                render(&render_thread_data->data);
                render_thread_data->data_changed = false;
            }
        }
    }
}