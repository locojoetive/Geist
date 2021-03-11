#include <iostream>
#include "Game.h"

Game* game = nullptr;

int main(int argc, const char* argv[]) {

	const int FPS = 60;
	const int frameDelay = 1000 / FPS;

	Uint32 frameStart;
	int frameTime;

	game = new Game();
	game->init("Geist", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 940, 600, false);
	while (game -> running()) 
	{
		// TODO: (1) handle any user input
		frameStart = SDL_GetTicks();
		game -> handleEvents();

		// (2) update all object eg positions etc
		game -> update();
		
		// (3) render changes to the display
		game -> render();

		frameTime = SDL_GetTicks() - frameStart;

		if (frameDelay > frameTime) 
		{
			SDL_Delay(frameDelay - frameTime);
		}
	}
	return 0;
}
