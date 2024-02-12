#include "Collision.h"
#include "Sprite.h"
#include "GameObject.h"

namespace engine {

bool spritesIntersect(const Sprite& sprite1, const Sprite& sprite2)
{
    return rectanglesIntersect(
        sprite1.position(),
        sprite1.position() + sprite1.size(),
        sprite2.position(),
        sprite2.position() + sprite2.size()
    );
}
}