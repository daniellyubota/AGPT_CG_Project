#pragma once

#include "Types.h"

namespace engine {

class GameObject;

class ComponentBase
{
public:
	ComponentBase() = default;
	ComponentBase(const ComponentBase& other) = default;
	virtual ~ComponentBase() = default;
	virtual void update(time_millis_t tickDuration) = 0;
	virtual void start() = 0;
	virtual void onCollisionEnter(GameObject& other) = 0;
};

}