#include "ClockImpl.h"
#include <SDL.h>

namespace engine {

ClockImpl::ClockImpl()
{
	this->timeFrom = SDL_GetTicks();
}

time_millis_t ClockImpl::getTime() const
{
	return SDL_GetTicks() - this->timeFrom;
}

time_millis_t ClockImpl::reset()
{
	auto time = getTime();
	this->timeFrom = SDL_GetTicks();
	return time;
}

}