#include "Position.h"

#include "../Util/Util.h"

namespace geng
{
    PositionComponent::PositionComponent(float data) : placeholder_data(data) {}

    void position_update(std::vector<PositionComponent> *components)
    {
        for (auto &component : *components)
        {   
            // TODO: do something
            LOG("Component value: " << component.placeholder_data);
        }
    }
}