#include "DefaultTextureLoader.h"
#include "ResourceManager.h"
using namespace engine;

void loadDefaultTextures()
{
	ResourceManager::LoadTexture("textures/lonerA.bmp", false, "enemy1");
	ResourceManager::LoadTexture("textures/lonerB.bmp", false, "enemy2");
	ResourceManager::LoadTexture("textures/lonerC.bmp", false, "enemy3");
	ResourceManager::LoadTexture("textures/ship1.bmp", false, "player");
	ResourceManager::LoadTexture("textures/missile.bmp", false, "missile");
	ResourceManager::LoadTexture("textures/saster96.bmp", false, "bigrock");
	ResourceManager::LoadTexture("textures/puweapon.bmp", false, "powerup");
	ResourceManager::LoadTexture("textures/galaxy2.bmp", false, "background");
	ResourceManager::LoadTexture("textures/saster32.bmp", false, "smallrock");
	ResourceManager::LoadTexture("textures/font16x16.bmp", false, "font");
	ResourceManager::LoadTexture("textures/explode64.bmp", false, "explosion");

}
