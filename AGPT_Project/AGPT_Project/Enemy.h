#pragma once
#include "GameObject.h"

class Enemy
{
public:
    Enemy(engine::GameObject* gameObject, int health);

    void update(engine::time_millis_t) {

    }

    void collide(engine::GameObject& other);
private:
    int health;
    engine::GameObject* object;
};

engine::GameObject* createEnemy(engine::GameEngine& engine, const engine::Vector2<float>& position);

void setupEnemies(engine::GameEngine& engine);