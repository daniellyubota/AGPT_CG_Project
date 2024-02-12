#include "SimpleMovement.h"
#include "GameObject.h"

SimpleMovement::SimpleMovement(engine::GameObject* obj, float speed): obj{obj}, speed{speed}
{
}

void SimpleMovement::update(engine::time_millis_t dt)
{
	obj->position().x() -= speed * engine::asSeconds(dt);
}
