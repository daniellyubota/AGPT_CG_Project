#pragma once
#include "GameObject.h"
#include "Vector2.h"
#include "Game.h"


class HealthBar
{
public:
	HealthBar(engine::GameObject* gameObject);
	void update(engine::time_millis_t dt) {};
	void setHp(int health);
private:
	engine::Sprite* sprite;
};

HealthBar* createHealthbar(const engine::Vector2<float>& position, engine::GameEngine& engine);