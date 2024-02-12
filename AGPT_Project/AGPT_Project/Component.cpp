#include "Component.h"
#include "GameObject.h"

namespace engine {

entity_id getObjectId(GameObject* o)
{
    return o->getObjectId();
}

}