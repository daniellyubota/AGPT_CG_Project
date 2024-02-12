#include <numeric>
#include "Animation.h"
#include "Sprite.h"
#include "GameObject.h"

namespace engine {

Animation::Animation(GameObject* obj)
{
	sprite = &obj->getComponent<Sprite>();
}

void Animation::update(time_millis_t dt)
{
	timeCounter += dt;
	if (timeCounter > frameDurationMilliseconds) {
		++counter;
		if (animations.contains(_currentAnimation)) {
			auto& anim = animations[_currentAnimation];
			int animIndex = counter % anim.size();
			if (!shouldRepeat && counter >= anim.size()) {
				animIndex = anim.size() - 1;
			}
			sprite->texture().setActiveFrame(anim[animIndex]);
			timeCounter = timeCounter % time_millis_t(frameDurationMilliseconds);
		}
	}
}

void Animation::setCurrentAnimation(std::string animation)
{
	if (animation == _currentAnimation) return;
	_currentAnimation = animation;
	counter = 0;
}

void Animation::addAnimation(std::string name, std::vector<int> frames)
{
	animations[name] = std::move(frames);
}

void Animation::setRepeat(bool shouldRepeat)
{
	this->shouldRepeat = shouldRepeat;
}

Animation& createDefaultAnimation(GameObject* go)
{
	auto& anim = go->create_component<Animation>().get_data();
	auto& sprite = go->getComponent<Sprite>();
	unsigned animLength = sprite.texture().getVaos().size();
	std::vector<int> frames(animLength);
	std::iota(frames.begin(), frames.end(), 0);
	anim.addAnimation("default", std::move(frames));
	anim.setCurrentAnimation("default");
	return anim;
}

}