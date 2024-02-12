#pragma once
#include "Types.h"

namespace engine {
class GameObject;
}

class SimpleMovement
{
public:
    SimpleMovement(engine::GameObject* obj, float speed = 50.0f);
    void update(engine::time_millis_t dt);
private:
    float speed;
    engine::GameObject* obj;
};

