//
// Created by Mikko Ryynänen on 19.11.2023.
//

#pragma once

enum CollisionLayer
{
    DEFAULT = 0,
    PLAYER = 1 << 0,
    PROJECTILE = 1 << 1,
    ENEMY = 1 << 2
};