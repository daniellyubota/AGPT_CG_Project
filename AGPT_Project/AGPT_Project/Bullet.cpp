#include "Bullet.h"

Bullet::Bullet(engine::GameObject* gameObject, int damage) : gameObject{ gameObject }, _damage{ damage }
{
}

void Bullet::collide(engine::GameObject& other)
{
	gameObject->Destroy();

}

int Bullet::damage() const
{
	return _damage;
}

void createBullet(engine::GameEngine& e, const engine::GameObject& player, int damage)
{
	auto& bullet = e.slateObject(player.position() + engine::Vector2<float>{56.0f, 24.0f}, BULLET, ENEMY);
	bullet.create_component<engine::Sprite>(engine::Vector2<float>{16, 16}, & engine::ResourceManager::GetTexture("missile"), 2, 3, 90.f);
	bullet.create_component<Bullet>(damage);
	auto& animationSet = bullet.create_component<engine::Animation>().get_data();
	std::vector<int> frames = { 0, 1 };
	if (damage == 2) frames = { 2, 3 };
	if (damage == 3) frames = { 4, 5 };
	animationSet.addAnimation("default", frames);
	animationSet.setCurrentAnimation("default");
	bullet.create_component<SimpleMovement>(-200.0f);
}

