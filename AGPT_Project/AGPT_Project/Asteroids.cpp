#include "Asteroids.h"
#include "Animation.h"
#include "SimpleMovement.h"
#include "CollisionTags.h"
#include "ResourceManager.h"

using namespace engine;

engine::GameObject* createAsteroid(engine::GameEngine& e, const engine::Vector2<float>& position)
{
    auto& obj = e.createObjectAt(position, ENEMY, BULLET);
    obj.create_component<Sprite>(Vector2<float>{96, 96}, & ResourceManager::GetTexture("bigrock"), 5, 5, 90.f);
    createDefaultAnimation(&obj);
    obj.create_component<SimpleMovement>(50.0f);
    obj.create_component<Asteroid>(10, true);
    return &obj;
}

void clutterUp(engine::GameEngine& e)
{
    createAsteroid(e, { 540, 50 });
    createAsteroid(e, { 740, 250 });
    createAsteroid(e, { 840, 125 });
    createAsteroid(e, { 1040, 100 });
    createAsteroid(e, { 1140, 300 });
    createAsteroid(e, { 1140, 50 });
    createAsteroid(e, { 1340, 250 });
    createAsteroid(e, { 1440, 125 });
    createAsteroid(e, { 1640, 100 });
    createAsteroid(e, { 2140, 300 });
    createAsteroid(e, { 2340, 250 });
    createAsteroid(e, { 2420, 125 });
    createAsteroid(e, { 2600, 100 });
    createAsteroid(e, { 3060, 300 });

}


void createTinyAsteroid(const Vector2<float>& position, GameEngine& e) {
    auto& obj = e.createObjectAt(position, ENEMY, BULLET);
    obj.create_component<Sprite>(Vector2<float>{32, 32}, & ResourceManager::GetTexture("smallrock"), 8, 2, 90.f);
    createDefaultAnimation(&obj);
    obj.create_component<SimpleMovement>(50.0f);
    obj.create_component<Asteroid>(2, false);
}

Asteroid::Asteroid(engine::GameObject* obj, int health, bool replicates) : gameObject{ obj }, health{ health }, replicates{ replicates }
{
    
}



void Asteroid::collide(engine::GameObject& other)
{
	--health;
	if (health <= 0) {
		auto& engine = *gameObject->engine();
        if (replicates) {
            createTinyAsteroid(gameObject->position() + Vector2<float>{-16, 0}, engine);
            createTinyAsteroid(gameObject->position() + Vector2<float>{-16, 64}, engine);
        }
		gameObject->Destroy();
	}
}
