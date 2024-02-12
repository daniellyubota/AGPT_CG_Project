#pragma once
#include "Game.h"
#include "GameObject.h"
#include "Vector2.h"

class Asteroid {
public:
	Asteroid(engine::GameObject* obj, int health, bool replicates);
	void update(engine::time_millis_t dt){}
	void collide(engine::GameObject& other);
private:
	bool replicates;
	int health;
	engine::GameObject* gameObject;
};


engine::GameObject* createAsteroid(engine::GameEngine& e, const engine::Vector2<float>& pos);

void clutterUp(engine::GameEngine& e);