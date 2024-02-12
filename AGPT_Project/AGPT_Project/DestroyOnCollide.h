#pragma once
#include "GameObject.h"

class DestroyOnCollide
{
public:
	DestroyOnCollide(engine::GameObject* obj);
	void update(engine::time_millis_t dt) {}
	void collide(engine::GameObject& other);
private:
	engine::GameObject* obj;
};

