#include "Enemy.h"
#include "CollisionTags.h"
#include "Animation.h"
#include "Game.h"
#include "SimpleMovement.h"
#include "ResourceManager.h"
#include "SpriteUtil.h"
#include "DestroyOnCollide.h"
using namespace engine;

Enemy::Enemy(engine::GameObject* gameObject, int health) : object{ gameObject }, health{ health }
{
}

void Enemy::collide(engine::GameObject& other)
{
    if (other.collisionTag() == BULLET) {
        --health;
        if (health <= 0) {
            if (std::rand() % 5 == 0) {
                Sprite* sp = createSprite(*object->engine(), object->position(), { 32, 32 }, POWERUP, PLAYER, &ResourceManager::GetTexture("powerup"), 4, 2);
                createDefaultAnimation(sp->getGameObject());
                sp->getGameObject()->create_component<SimpleMovement>(100.0f);
                sp->getGameObject()->create_component<DestroyOnCollide>();
            }
            object->Destroy();
        }
    }
}

engine::GameObject* createEnemy(engine::GameEngine& engine, const engine::Vector2<float>& position)
{
    int tex = std::rand() % 3 + 1;
    auto& enemy = engine.createObject(ENEMY, BULLET | PLAYER);
    enemy.position() = position;
    enemy.create_component<Sprite>(Vector2<float>{64, 64}, & ResourceManager::GetTexture(std::string("enemy") + std::to_string(tex)), 4, 4);
    createDefaultAnimation(&enemy);
    enemy.create_component<SimpleMovement>(50.0f);
    enemy.create_component<Enemy>(3);
    return &enemy;
}

void setupEnemies(engine::GameEngine& engine)
{
    createEnemy(engine, { 740, 200 });
    createEnemy(engine, { 940, 400 });
    createEnemy(engine, { 890, 350 });
    createEnemy(engine, { 1040, 120 });
    createEnemy(engine, { 1140, 140 });
    createEnemy(engine, { 1240, 420 });
    createEnemy(engine, { 1340, 200 });
    createEnemy(engine, { 1740, 400 });
    createEnemy(engine, { 2140, 100 });
    createEnemy(engine, { 2440, 170 });
    createEnemy(engine, { 2840, 350 });
    createEnemy(engine, { 2640, 420 });
    createEnemy(engine, { 3040, 190 });
    createEnemy(engine, { 3240, 200 });
    createEnemy(engine, { 3240, 400 });
    createEnemy(engine, { 3490, 350 });
    createEnemy(engine, { 3640, 120 });
    createEnemy(engine, { 4140, 140 });
    createEnemy(engine, { 4240, 420 });
    createEnemy(engine, { 4340, 200 });
    createEnemy(engine, { 4740, 400 });
    createEnemy(engine, { 5140, 100 });
    createEnemy(engine, { 5440, 170 });
    createEnemy(engine, { 5840, 350 });
    createEnemy(engine, { 5640, 420 });
    createEnemy(engine, { 6040, 190 });


}
