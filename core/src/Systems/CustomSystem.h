#pragma once

namespace geng
{
    class CustomSystem
    {
    public:
        virtual ~CustomSystem() = default;
        virtual void update() = 0;
    };
}