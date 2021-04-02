#pragma once

#include <SDL.h>
#undef main
#include <SDL_image.h>
#include <iostream>
#include "GameObject/GameObject.h"

namespace GameSpace {

	class Game
	{
	public:
		Game();
		~Game();

		void init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen);
		void handleEvents();
		void update();
		void render();
		void clean();
		bool running() { return isRunning; }

		static SDL_Renderer* renderer;
	private:
		int count = 0;
		bool isRunning = false;
		SDL_Window* window;
	};
}