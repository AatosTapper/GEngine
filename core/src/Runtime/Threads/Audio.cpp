#include "Audio.h"

#include "../../Util/Util.h"

#include <thread>
#include <mutex>
#include <condition_variable>
#include <atomic>

namespace geng
{
    static void process_audio(AudioData *data)
    {
        //THREAD_LOG_STR("Processing audio");
    }

    void audio_thread(AudioThreadData *audio_thread_data, std::atomic<bool> &stop_threads)
    {
        while (!audio_thread_data->stop_thread)
        {
            std::unique_lock<std::mutex> lock(audio_thread_data->mutex);
            audio_thread_data->cv.wait(lock, [&] { return audio_thread_data->data_changed || stop_threads; });

            if (!stop_threads)
            {
                process_audio(&audio_thread_data->data);
                audio_thread_data->data_changed = false;
            }
        }
    }
}