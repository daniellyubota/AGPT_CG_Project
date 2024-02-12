#pragma once
#include <unordered_map>
#include <vector>
#include <string>
#include "Types.h"

namespace engine {

class Sprite;
class GameObject;



class Animation
{
public:
	Animation(GameObject* obj);
	void update(time_millis_t dt);
	void setCurrentAnimation(std::string animation);
	void addAnimation(std::string name, std::vector<int> frames);
	void setRepeat(bool shouldRepeat);

private:
	unsigned int counter = 0;
	time_millis_t timeCounter = 0;
	std::string _currentAnimation;
	Sprite* sprite;
	std::unordered_map<std::string, std::vector<int>> animations;
	float frameDurationMilliseconds = 100;
	bool shouldRepeat = true;
};

Animation& createDefaultAnimation(GameObject* go);
}