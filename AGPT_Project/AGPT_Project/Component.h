#pragma once
#include <utility>
#include <iostream>
#include "ComponentBase.h"
#include "types.h"
#include "util.h"

namespace engine {

class GameObject;


entity_id getObjectId(GameObject* o);


template<class T, class ...Args>
concept objectDependentComponent = requires(T a, GameObject * g, Args... args) {
	{ T(g, std::forward<Args>(args)...) };
};

template<class T, class ...Args>
concept objectInependentComponent = requires(T a, Args... args) {
	{ T(std::forward<Args>(args)...) };
};


template<class T>
concept updatable = requires(T a, time_millis_t t) {
	{ a.update(t) };
};


template<class T>
concept startable = requires(T a) {
	{ a.start() };
};

template<class T>
concept Collidable = requires(T & a, GameObject & b) {
	{ a.collide(b) };
};
template <updatable T>
class Component : public ComponentBase {
public:
	Component(GameObject* go) : id(generate_id<T>()), gameObject(go), data([&] {
		if constexpr (objectDependentComponent<T>) {
			return T{ gameObject };
		}
		else {
			return T{};
		}
		}()) {

	};
	template<class ...Args>
	Component(GameObject* go, Args&&... args)
		: id(generate_id<T>()), gameObject(go), data(gameObject, std::forward<Args>(args)...) {

	}
	~Component() = default;

	inline entity_id get_object_id() const { return getObjectId(gameObject); };
	inline component_id get_id() const { return id; };
	inline T& get_data() { return data; };
	inline const T& get_data() const { return data; };

	inline static component_type_id get_type_id() { return type_id; };

	void update(time_millis_t tickDuration) override {
		data.update(tickDuration);
	}
	void start() override {
		if constexpr (startable<T>) {
			data.start();
		}
	}

	void onCollisionEnter(GameObject& other) override {
		if constexpr (Collidable<T>) {
			data.collide(other);
		}
		else {
		}
	}
private:
	GameObject* gameObject;
	T data;
	const component_id id;
	static const component_type_id type_id;
};

template<updatable T>
const component_type_id Component<T>::type_id = generate_type_id<T>();

}