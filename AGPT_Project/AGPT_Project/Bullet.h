#pragma once
#include "GameObject.h"
#include "Animation.h"
#include "Sprite.h"
#include "Game.h"
#include "SimpleMovement.h"
#include "ResourceManager.h"
#include "CollisionTags.h"

class Bullet
{
public:
	Bullet(engine::GameObject* gameObject, int damage);
	void update(engine::time_millis_t dt) {
		if (gameObject->position().x() > 660) gameObject->Destroy();
	}
	void collide(engine::GameObject& other);

	int damage() const;
private:
	int _damage;
	engine::GameObject* gameObject;
};

void createBullet(engine::GameEngine& e, const engine::GameObject& player, int damage);