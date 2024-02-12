#pragma once
#include "Vector2.h"

namespace engine {
class Sprite;

template<class T>
bool rectanglesIntersect(
    T minAx, T minAy, T maxAx, T maxAy,
    T minBx, T minBy, T maxBx, T maxBy) {
    auto aLeftOfB = maxAx < minBx;
    auto aRightOfB = minAx > maxBx;
    auto aAboveB = minAy > maxBy;
    auto aBelowB = maxAy < minBy;

    return !(aLeftOfB || aRightOfB || aAboveB || aBelowB);
}

template<class T>
bool rectanglesIntersect(const Vector2<T>& minA, const Vector2<T>& maxA, const Vector2<T>& minB, const Vector2<T>& maxB) {
    return rectanglesIntersect(minA.x(), minA.y(), maxA.x(), maxA.y(), minB.x(), minB.y(), maxB.x(), maxB.y());
}

bool spritesIntersect(const Sprite& sprite1, const Sprite& sprite2);

}