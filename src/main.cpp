#include <iostream>
#include "Game/Game.h"


int main(int argc, const char* argv[]) {

	const int FPS = 60;
	const int frameDelay = 1000 / FPS;

	Uint32 frameStart;
	int frameTime;

	Game* game = new Game();
	game->init("Geist", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 940, 640, false);
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

struct StructA {
	int a;
	char b;
};

int operator^(StructA a, StructA b) {
	return a.a - b.a;
}

int main0 ()
{
	StructA a;
	StructA b;
	a.a = 14;
	b.a = 5;
	std::cout << (a ^ b) << std::endl;
	return 0;
}
