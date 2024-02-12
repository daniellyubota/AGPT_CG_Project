#pragma once
#include <vector>
#include "Texture.h"

namespace engine {

class SpriteTexture
{
public:
	SpriteTexture(Texture2D& texture, int columns = 1, int rows = 1);
	unsigned int vao() const;
	void setActiveFrame(int index);
	const Texture2D& texture() const;
	const std::vector<unsigned int>& getVaos() const;
private:
	int index = 0;
	std::vector<unsigned int> VAOs;
	Texture2D& _texture;
};

}