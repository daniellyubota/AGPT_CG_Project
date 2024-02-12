#include "Sprite.h"
#include <GL/glew.h>

namespace engine {


Sprite::Sprite(GameObject* obj, const Vector2<float>& size, Texture2D* texture, int columns, int rows, float rotation) : obj{ obj }, _size{ size }, _texture{ SpriteTexture(*texture, columns, rows) },_rotation(rotation)
{
    _shader = spriteShader;
}

Shader& Sprite::shader()
{
    return *_shader;
}

const Shader& Sprite::shader() const
{
    return *_shader;
}

const SpriteTexture Sprite::texture() const
{
    return _texture;
}

SpriteTexture& Sprite::texture()
{
    return _texture;
}

const Vector2<float>& Sprite::size() const
{
    return _size;
}

const float& Sprite::rotation() const
{
    return _rotation;
}

const Vector2<float>& Sprite::position() const
{
    return obj->position();
}

GameObject* Sprite::getGameObject()
{
    return obj;
}

void Sprite::setDefaultShader(Shader& shader)
{
    spriteShader = &shader;
}


Shader* Sprite::spriteShader = nullptr;

}