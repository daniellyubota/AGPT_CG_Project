#pragma once
#include "GameObject.h"
#include "Texture.h"
#include "TextureFragment.h"
#include "Shader.h"

namespace engine {

class Sprite
{
public:
	Sprite(GameObject* obj, const Vector2<float>& size, Texture2D* texture, int columns = 1, int rows = 1, float rotation = 0);
	Shader& shader();
	const Shader& shader() const;
	const SpriteTexture texture() const;
	SpriteTexture& texture();
	const Vector2<float>& size() const;
	const Vector2<float>& position() const;
	GameObject* getGameObject();
	const float& rotation() const;


	static void setDefaultShader(Shader& shader);

	void update(time_millis_t time) {}
private:
	GameObject* obj;
	Vector2<float> _size;
	Shader* _shader;
	SpriteTexture _texture;
	float _rotation;

	static Shader* spriteShader;
};

}