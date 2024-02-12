#pragma once
#include <memory>
#include <string>
#include "Vector2.h"

struct SDL_Window;

namespace engine {
class Window
{
public:
	Window(const std::string& name, const Vector2<int>& position, const Vector2<int>& dimensions);
	Window(const Window& other) = delete;
	Window& operator=(const Window& other) = delete;
	~Window();

	void enterFullscreen();
	void exitFullscreen();
	void toggleFullscreen();
	bool isFullscreen();
	SDL_Window* getHandle();

private:
	Vector2<int> position, dimensions;
	bool fullscreen;
	static std::uint32_t FLAGS;
	SDL_Window* _windowHandle;
};

}