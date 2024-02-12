#include "PlayerController.h"
#include "GameObject.h"
#include "Animation.h"
#include "Sprite.h"
#include "Bullet.h"

using namespace engine;

PlayerController::PlayerController(GameObject* go) : gameObject{ go }, animation{ &go->getComponent<Animation>() }, sprite{ &go->getComponent<Sprite>() }
{
}

void PlayerController::walkLeft(bool walk)
{
	_walkLeft = walk;
	
}

void PlayerController::walkRight(bool walk)
{
	_walkRight = walk;
	
}

void PlayerController::walkUp(bool walk)
{
	_walkUp = walk;
	updateAnimation();
}

void PlayerController::walkDown(bool walk)
{
	_walkDown = walk;
	updateAnimation();
}
void PlayerController::shooting(bool shoot)
{
	_shooting = shoot;
}

void PlayerController::updateAnimation()
{
	if (_walkUp) {
		animation->setCurrentAnimation("up");
	}
	else if (_walkDown) {
		animation->setCurrentAnimation("down");
	}
	else {
		animation->setCurrentAnimation("default");
	}
}

void PlayerController::update(time_millis_t dt)
{
	if (_walkLeft) {
		gameObject->position().x() -= asSeconds(dt) * speed;
	}
	else if (_walkRight) {
		gameObject->position().x() += asSeconds(dt) * speed;
	}
	if (_walkUp) {
		gameObject->position().y() -= asSeconds(dt) * speed;
	}
	else if (_walkDown) {
		gameObject->position().y() += asSeconds(dt) * speed;
	}

	totalTime += dt;
	if (_shooting) {
		if (totalTime >= shootInterval) {
			totalTime = totalTime % shootInterval;
			auto& engine = *gameObject->engine();
			createBullet(engine, *gameObject, damage);
		}
	}
	graceTimeTotal += dt;
}

void PlayerController::collide(GameObject& other)
{
	if (other.collisionTag() & ENEMY) {
		if (graceTimeTotal >= graceInterval) {
			--health;
			graceTimeTotal = 0;
		}
		if (damage > 1) {
			--damage;
		}
		if (health <= 0) {
			std::exit(0);
		}
	}
	else if (other.collisionTag() & POWERUP) {
		if (damage < 3) {
			++damage;
		}
	}
}

int PlayerController::hp() const
{
	return health;
}

engine::GameObject* createPlayer(engine::GameEngine& engine)
{
	GameObject* player = &engine.createObject(CollisionTags::PLAYER, CollisionTags::ENEMY | CollisionTags::POWERUP);
	player->position() = { 80, 224 };
	auto& sprite = player->create_component<Sprite>(Vector2<float>{64, 64}, & ResourceManager::GetTexture("player"), 7, 1, 90.f).get_data();
	sprite.texture().setActiveFrame(3);
	auto& animationSet = player->create_component<Animation>().get_data();
	animationSet.setRepeat(false);
	animationSet.addAnimation("default", { 3 });
	animationSet.addAnimation("up", { 2, 1, 0 });
	animationSet.addAnimation("down", { 4, 5, 6 });
	animationSet.setCurrentAnimation("default");
	player->create_component<PlayerController>();
	return player;
}
