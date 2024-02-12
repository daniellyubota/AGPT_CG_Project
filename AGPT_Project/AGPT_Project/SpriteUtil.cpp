#include "SpriteUtil.h"

engine::Sprite* createSprite(engine::GameEngine& e, engine::Vector2<float> position, engine::Vector2<float> size, std::uint64_t tag, std::uint64_t matrix, engine::Texture2D* texture, int columns, int rows)
{
    auto& obj = e.slateObject(position, tag, matrix);
    auto& spr = obj.create_component<engine::Sprite>(size, texture, columns, rows);
    return &spr.get_data();
}