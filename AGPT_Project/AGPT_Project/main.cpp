#include <iostream>
#include <SDL.h>
#include <GL/glew.h>
#include <SDL_opengl.h>
#include <math.h>
#include <cassert>
#include <vector>
#include "ResourceManager.h"
#include "GameObject.h"
#include "Window.h"
#include "Clock.h"
#include "filesystem"
#include "Game.h"
#include "Animation.h"
#include "TextureFragment.h"
#include "PlayerController.h"
#include "DefaultTextureLoader.h"
#include "Asteroids.h"
#include "SimpleMovement.h"
#include "CollisionTags.h"
#include "HealthBar.h"
#include "Enemy.h"
#include <fstream>
#include "Bullet.h"

using namespace engine;

const int width = 640;
const int height = 480;
const unsigned tick_duration = 1000 / 60;

void initGameObjects(GameEngine& game);

GameObject* player = nullptr;
GameObject* test = nullptr;

class CollisionTest {
public:
    CollisionTest(GameObject* gameObject) {
        this->obj = gameObject;

    }
    void update(time_millis_t dt) {
        
    }

    void collide(GameObject& other) {
        obj->Destroy();
    }
private:
    GameObject* obj;
};





int main(int argc, char** argv)
{
    std::srand(std::time(nullptr));
    Window w{
        "OpenGL Test",
        {100, 100},
        {width, height}
    };
    
    
    GameEngine g{width, height};
    g.Init();
    loadDefaultTextures();
    initGameObjects(g);
    player = createPlayer(g);
    clutterUp(g);
    setupEnemies(g);
    HealthBar* hb = createHealthbar({ 550, 450 }, g);
    Clock clock(tick_duration);
    glViewport(0, 0, width, height);

    bool running = true;
    while (running)
    {
        SDL_Event Event;
        while (SDL_PollEvent(&Event))
        {
            if (Event.type == SDL_KEYDOWN)
            {
                switch (Event.key.keysym.sym)
                {
                case SDLK_ESCAPE:
                    running = false;
                    break;
                case 'f':
                    w.toggleFullscreen();
                    break;
                case 'a': 
                    player->getComponent<PlayerController>().walkLeft(true);
                    break;
                case 'd':
                    player->getComponent<PlayerController>().walkRight(true);
                    break;
                case 'w':
                    player->getComponent<PlayerController>().walkUp(true);
                    break;
                case 's':
                    player->getComponent<PlayerController>().walkDown(true);
                    break;
                case SDLK_SPACE:
                    player->getComponent<PlayerController>().shooting(true);
                    break;

                default:
                    break;
                }
            }
            else if (Event.type == SDL_KEYUP) {
                switch (Event.key.keysym.sym) {
                case 'a':
                    player->getComponent<PlayerController>().walkLeft(false);
                    break;
                case 'd':
                    player->getComponent<PlayerController>().walkRight(false);
                    break;
                case 'w':
                    player->getComponent<PlayerController>().walkUp(false);
                    break;
                case 's':
                    player->getComponent<PlayerController>().walkDown(false);
                    break;

                case SDLK_SPACE:
                    player->getComponent<PlayerController>().shooting(false);
                    break;

                }
            }
            else if (Event.type == SDL_QUIT)
            {
                running = false;
            }
        }
        hb->setHp(player->getComponent<PlayerController>().hp());
        
        for (unsigned tick : clock.drain()) {
            g.Update(tick);
        }

        glClearColor(1.f, 1.f, 1.f, 0.f);
        glClear(GL_COLOR_BUFFER_BIT);

        g.Render();

        SDL_GL_SwapWindow(w.getHandle());
    }


    return 0;
}


void initGameObjects(GameEngine& game) {
    auto& background = game.createObject();
    background.create_component<Sprite>(Vector2<float>{ float(width), float(height) }, & ResourceManager::GetTexture("background"));
}

