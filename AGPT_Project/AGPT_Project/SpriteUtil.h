#pragma once
#include "GameObject.h"
#include "Sprite.h"
#include "Texture.h"
#include "Game.h"

engine::Sprite* createSprite(engine::GameEngine& e, engine::Vector2<float> position, engine::Vector2<float> size, std::uint64_t tag, std::uint64_t matrix, engine::Texture2D* texture, int columns, int rows);