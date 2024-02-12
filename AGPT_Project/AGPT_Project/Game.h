#pragma once
#include "Shader.h"
#include <fstream>
#include "GameObject.h"
#include "Sprite.h"
#include <vector>
#include <set>
#include <memory>

namespace engine {


enum GameState {
    GAME_ACTIVE,
    GAME_MENU,
    GAME_WIN
};
class GameEngine
{
public:
    GameState State;
    bool Keys[1024];
    unsigned int Width, Height;
    GameEngine(unsigned int width, unsigned int height);
    ~GameEngine();
    void Init();
    void ProcessInput(float dt);
    void Update(time_millis_t millis);
    void Render();
    GameObject& createObject(std::uint64_t collisionTag = 0, std::uint64_t collisionMatrix = 0);
    GameObject& createObjectAt(const Vector2<float>& initialPosition, std::uint64_t collisionTag = 0, std::uint64_t collisionMatrix = 0);
    GameObject& slateObject(const Vector2<float>& initialPosition, std::uint64_t collisionTag = 0, std::uint64_t collisionMatrix = 0);
    void DestroyObject(GameObject* obj);
    std::vector<std::unique_ptr<GameObject>>& gameObjects();
private:
    std::vector<std::unique_ptr<GameObject>> _gameObjects;
    std::vector<std::unique_ptr<GameObject>> slatedObjects;
    std::set<GameObject*> destroyedObjects;
};
}