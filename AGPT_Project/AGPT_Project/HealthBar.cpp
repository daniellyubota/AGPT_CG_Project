#include "HealthBar.h"
#include "Sprite.h"
#include "ResourceManager.h"
using namespace engine;

HealthBar* createHealthbar(const engine::Vector2<float>& position, engine::GameEngine& engine)
{
    auto& go = engine.slateObject(position);
    go.create_component<Sprite>(Vector2<float>{16, 16}, &ResourceManager::GetTexture("font"), 8, 12);
    auto& hb = go.create_component<HealthBar>().get_data();
    return &hb;
}


HealthBar::HealthBar(engine::GameObject* gameObject) : sprite { &gameObject->getComponent<Sprite>() }
{

}

void HealthBar::setHp(int health)
{
    sprite->texture().setActiveFrame(health + 16);
}
