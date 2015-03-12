#ifndef _TIMER_HPP_
#define _TIMER_HPP_

#include <iostream>
#include <SDL.h>
#include <SDL_image.h>
class Timer
{
	public:
		//constructor
		Timer();
		//start the clock
		void start();
		//return the timers time
		Uint32 getTime();

		//timer start flag
		bool started;
		
	private:
		
		//The started Ticks value
		Uint32 startTicks;
};

#endif
