#include "../include/GEngine.h"

#include <iostream>

namespace GEng
{
    void init()
    {
        LOG("Initializing GEngine");
        TRACK_PERFORMANCE("Init test", {
            // DO SOMETHING
        });
    }
}