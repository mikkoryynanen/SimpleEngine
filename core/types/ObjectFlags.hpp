//
// Created by Mikko Ryynänen on 18.11.2023.
//

#pragma once

enum ObjectFlags
{
    NONE = 0,
    CLAMP_FOR_SCREEN = 1 << 0,
    DESTROY_OUTSIDE_SCREEN = 1 << 1
};

class Flags final
{
public:
    bool hasFlag(ObjectFlags flag) const
    {
        return (flags & flag) != 0;
    }

    void setFlag(ObjectFlags flag)
    {
        flags = static_cast<ObjectFlags>(flags | flag);
    }

    // Unset a flag
    void unsetFlag(ObjectFlags flag)
    {
        flags = static_cast<ObjectFlags>(flags & ~flag);
    }

private:
    ObjectFlags flags;
};