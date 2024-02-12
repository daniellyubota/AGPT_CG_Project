#pragma once

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

#include "texture.h"
#include "shader.h"
#include "Sprite.h"

namespace engine {


class SpriteRenderer
{
public:
    SpriteRenderer();
    ~SpriteRenderer();
    void DrawSprite(const Sprite& sprite);
private:
    unsigned int quadVAO;
    void initRenderData();
};

}