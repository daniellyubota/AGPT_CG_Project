#include "Window.h"
#include <SDL.h>
#include <GL/glew.h>

namespace engine {

std::uint32_t Window::FLAGS = SDL_WINDOW_OPENGL;

Window::Window(const std::string& name, const Vector2<int>& position, const Vector2<int>& dimensions) : position{ position }, dimensions{ dimensions }
{
	SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
	glViewport(0, 0, dimensions.x(), dimensions.y());
	_windowHandle = SDL_CreateWindow(name.c_str(), position.x(), position.y(), dimensions.x(), dimensions.y(), FLAGS);
	SDL_GL_CreateContext(_windowHandle);
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	glewInit();
}

Window::~Window()
{
	SDL_DestroyWindow(_windowHandle);
}

void Window::enterFullscreen()
{
	SDL_SetWindowFullscreen(_windowHandle, FLAGS | SDL_WINDOW_FULLSCREEN_DESKTOP);
	fullscreen = true;
}

void Window::exitFullscreen()
{
	SDL_SetWindowFullscreen(_windowHandle, FLAGS);
	fullscreen = false;
}

void Window::toggleFullscreen()
{
	if (fullscreen) {
		exitFullscreen();
	}
	else {
		enterFullscreen();
	}
}

bool Window::isFullscreen()
{
	return fullscreen;
}

SDL_Window* Window::getHandle()
{
	return _windowHandle;
}

}