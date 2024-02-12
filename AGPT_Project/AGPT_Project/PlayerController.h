#pragma once
#include "Types.h"

namespace engine {

class GameObject;
class Animation;
class Sprite;
class GameEngine;
}

class PlayerController
{
public:
	PlayerController(engine::GameObject* go);
	void walkLeft(bool walk);
	void walkRight(bool walk);
	void walkUp(bool walk);
	void walkDown(bool walk);
	void shooting(bool shoot);
	void updateAnimation();
	void update(engine::time_millis_t dt);
	void collide(engine::GameObject& other);
	int hp() const;
private:
	int health = 5;
	int damage = 1;
	engine::GameObject* gameObject;
	engine::Animation* animation;
	engine::Sprite* sprite;
	bool _walkLeft = false;
	bool _walkRight = false;
	bool _walkUp = false;
	bool _walkDown = false;
	bool _shooting = false;
	float speed = 150;
	engine::time_millis_t shootInterval = 200;
	engine::time_millis_t totalTime = 0;
	engine::time_millis_t graceInterval = 1000;
	engine::time_millis_t graceTimeTotal = 0;
};

engine::GameObject* createPlayer(engine::GameEngine& engine);