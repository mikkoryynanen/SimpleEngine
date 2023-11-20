//
// Created by Mikko Ryynänen on 18.11.2023.
//

#pragma once

enum ObjectFlags
{
    NONE = 0,
    CLAMP_FOR_SCREEN = 1 << 0,
    DESTROY_OUTSIDE_SCREEN = 1 << 1,
    QUEUE_FOR_DESTROY = 1 << 2
};

template<typename T>
class Flags final
{
public:
    bool hasFlag(T flag) const
    {
        return (flags & flag) != 0;
    }

    void setFlag(T flag)
    {
        flags = static_cast<T>(flags | flag);
    }

    void unsetFlag(T flag)
    {
        flags = static_cast<T>(flags & ~flag);
    }

    T getFlags() const
    {
        return flags;
    }

private:
    T flags;
};

