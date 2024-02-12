#include "GameObject.h"
#include "Game.h"

namespace engine {

GameObject::GameObject(GameEngine* engine, std::uint64_t collisionTag, std::uint64_t collisionMatrix) : _engine{ engine }, _collisionTag{ collisionTag }, collisionMatrix{ collisionMatrix }
{
	objectId = generate_id<GameObject>();
}

void GameObject::Destroy()
{
	_engine->DestroyObject(this);
}

void GameObject::update(time_millis_t tickDuration)
{
	for (auto& c : components) {
		c.second->update(tickDuration);
	}
}

void GameObject::collide(GameObject& other)
{
	for (auto& c : components) {
		c.second->onCollisionEnter(other);
	}
}

std::uint64_t& GameObject::collisionTag()
{
	return _collisionTag;
}

std::uint64_t GameObject::collisionTag() const
{
	return _collisionTag;
}


Vector2<float>& GameObject::position()
{
	return _position;
}

const Vector2<float>& GameObject::position() const
{
	return _position;
}

GameEngine* GameObject::engine()
{
	return _engine;
}

bool GameObject::canCollideWith(const GameObject& other) const
{
	return collisionMatrix & other._collisionTag;
}

}