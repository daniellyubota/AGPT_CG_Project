#pragma once
#include <unordered_map>
#include <memory>
#include <cstdint>
#include "Types.h"
#include "Component.h"
#include "Vector2.h"

namespace engine {

class GameEngine;
class GameObject
{
public:
	GameObject(GameEngine* engine, std::uint64_t collisionTag = 0, std::uint64_t collisionMatrix = 0);
	GameObject(const GameObject& other) = delete;
	GameObject(GameObject&& other) = delete;

	GameObject& operator=(const GameObject& other) = delete;
	GameObject& operator=(GameObject&& other) = delete;
	template<class T, class ...Args>
	Component<T>& create_component(Args... args) {
		component_type_id type_id = Component<T>::get_type_id();
		auto comp = new Component<T>(this, std::forward<Args>(args)...);
		components[type_id] = std::unique_ptr<ComponentBase>(comp);
		return *comp;
	}
	template<class T>
	decltype(std::declval<Component<T>>().get_data()) getComponent() {
		return static_cast<Component<T>&>(*components[Component<T>::get_type_id()]).get_data();
	}
	entity_id getObjectId() const {
		return objectId;
	}

	void Destroy();
	void update(time_millis_t tickDuration);
	void collide(GameObject& other);

	std::uint64_t& collisionTag();
	std::uint64_t collisionTag() const;

	Vector2<float>& position();
	const Vector2<float>& position() const;
	GameEngine* engine();
	bool canCollideWith(const GameObject& other) const;

private:
	std::uint64_t collisionMatrix;
	std::uint64_t _collisionTag;
	GameEngine* _engine;
	std::unordered_map<component_type_id, std::unique_ptr<ComponentBase>> components;
	Vector2<float> _position;

	entity_id objectId;
};

}