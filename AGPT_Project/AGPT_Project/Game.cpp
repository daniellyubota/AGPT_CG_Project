#include "Game.h"
#include "ResourceManager.h"
#include "SpriteRenderer.h"
#include <GL/glew.h>
#include <glm/gtc/type_ptr.hpp>
#include <iostream>
#include "Collision.h"

namespace engine {
SpriteRenderer* Renderer;


GameEngine::GameEngine(unsigned int width, unsigned int height)
    : State(GAME_ACTIVE), Keys(), Width(width), Height(height)
{
}

GameEngine::~GameEngine()
{
    delete Renderer;
}

void GameEngine::Init()
{
    glewInit();
    ResourceManager::LoadShader("shaders/sprite.vs", "shaders/sprite.frag", nullptr, "sprite");
    glm::mat4 projection = glm::ortho(0.0f, static_cast<float>(this->Width),
        static_cast<float>(this->Height), 0.0f, -1.0f, 1.0f);
    auto& shader = ResourceManager::GetShader("sprite");
    glUseProgram(shader.getID());
    glUniform1i(glGetUniformLocation(shader.getID(), "image"), 0);
    glUniformMatrix4fv(glGetUniformLocation(shader.getID(), "projection"), 1, false, glm::value_ptr(projection));
    Sprite::setDefaultShader(shader);
    Renderer = new SpriteRenderer();
}

void GameEngine::Update(time_millis_t millis)
{
    _gameObjects.insert(_gameObjects.end(), std::make_move_iterator(slatedObjects.begin()), std::make_move_iterator(slatedObjects.end()));
    slatedObjects.clear();
    for (auto& obj : _gameObjects) {
        obj->update(millis);
    }

    _gameObjects.erase(std::remove_if(_gameObjects.begin(), _gameObjects.end(), [&](std::unique_ptr<GameObject>& o) { return destroyedObjects.contains(o.get()); }), _gameObjects.end());
    destroyedObjects.clear();

    for (auto o1 = _gameObjects.begin(); o1 != _gameObjects.end(); ++o1) {
        for (auto o2 = std::next(o1); o2 != _gameObjects.end(); ++o2) {
            if (spritesIntersect((*o1)->getComponent<Sprite>(), (*o2)->getComponent<Sprite>())) {

                if ((*o1)->canCollideWith(**o2)) {
                    (*o1)->collide(**o2);
                }
                if ((*o2)->canCollideWith(**o1)) {
                    (*o2)->collide(**o1);
                }
            }
        }
    }
}

void GameEngine::ProcessInput(float dt)
{

}

void GameEngine::Render()
{
    for (auto& obj : _gameObjects) {
        Renderer->DrawSprite(obj->getComponent<Sprite>());
    }
}

GameObject& GameEngine::createObject(std::uint64_t collisionTag, std::uint64_t collisionMatrix)
{
    _gameObjects.push_back(std::make_unique<GameObject>(this, collisionTag, collisionMatrix));
    return *_gameObjects.back();
}

GameObject& GameEngine::createObjectAt(const Vector2<float>& initialPosition, std::uint64_t collisionTag, std::uint64_t collisionMatrix)
{
    auto& o = createObject(collisionTag, collisionMatrix);
    o.position() = initialPosition;
    return o;
}

GameObject& GameEngine::slateObject(const Vector2<float>& initialPosition, std::uint64_t collisionTag, std::uint64_t collisionMatrix)
{
    slatedObjects.push_back(std::make_unique<GameObject>(this, collisionTag, collisionMatrix));
    auto& obj = *slatedObjects.back();
    obj.position() = initialPosition;
    return obj;
}

void GameEngine::DestroyObject(GameObject* obj)
{
    destroyedObjects.insert(obj);
}


std::vector<std::unique_ptr<GameObject>>& GameEngine::gameObjects()
{
    return _gameObjects;
}

}