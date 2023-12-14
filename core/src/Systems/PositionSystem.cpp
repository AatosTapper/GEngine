#include "PositionSystem.h"

#include "../Util/Util.h"

namespace geng
{
    void position_system_update(std::vector<PositionComponent> *components)
    {
        if (components == nullptr)
            return;
            
        for (auto &component : *components)
        {   
            // TODO: do something
            //LOG("Component value: " << component.placeholder_data);
        }
    }
}