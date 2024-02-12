#pragma once
#include <cstdint>

enum CollisionTags : std::uint64_t {
    PLAYER = 0x1,
    ENEMY = 0x2,
    POWERUP = 0x4,
    BULLET = 0x8
};