#include "DestroyOnCollide.h"

DestroyOnCollide::DestroyOnCollide(engine::GameObject* obj) : obj{ obj }
{
}

void DestroyOnCollide::collide(engine::GameObject& other)
{
	obj->Destroy();
}
