#include "headers/timer.hpp"
//constructor
Timer::Timer()
{
	started = false;
	startTicks = 0;
}
//start the clock
void Timer::start()
{
	started = true;
	startTicks = SDL_GetTicks();
}
//return the timers time
Uint32 Timer::getTime()
{
	if( started )
		return SDL_GetTicks() - startTicks;
}
