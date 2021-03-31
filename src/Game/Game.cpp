#include "Game.h"

#include "GameObject/TextureManager/TextureManager.h"

namespace GameSpace {
	Game::Game() {
		window = nullptr;
		renderer = nullptr;
		player = nullptr;
		isRunning = false;
	}

	Game::~Game() {

	}

	void Game::init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen)
	{
		int flags = 0;
		if (fullscreen)
		{
			flags = SDL_WINDOW_FULLSCREEN;
		}

		if (SDL_Init(SDL_INIT_EVERYTHING) == 0)
		{
			std::cout << "Subsystems Initialized...." << std::endl;
			window = SDL_CreateWindow(title, xpos, ypos, width, height, flags);
			if (window)
			{
				std::cout << "Window created!" << std::endl;
			}

			renderer = SDL_CreateRenderer(window, -1, flags);
			if (renderer)
			{
				SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
				std::cout << "Renderer created!" << std::endl;
			}
			isRunning = true;
		}
		else {
			isRunning = false;
		}

		Maf::Vector* startPos = new Maf::Vector(0, 0);
		player = new GameObject("assets/sword/sword_0.png", renderer, startPos);
	}

	void Game::handleEvents()
	{
		SDL_Event event;
		SDL_PollEvent(&event);
		switch (event.type) {
			case SDL_QUIT:
				isRunning = false;
				break;
			default:
				break;
		}
	}

	void Game::update()
	{
		count++;

		// Sword
		player->Update();

		std::cout << count << std::endl;
	}

	void Game::render()
	{
		SDL_RenderClear(renderer);
		// Sword
		player->Render();
		SDL_RenderPresent(renderer);
	}

	void Game::clean()
	{
		SDL_DestroyWindow(window);
		SDL_DestroyRenderer(renderer);
		SDL_Quit();
		std::cout << "Game Cleaned" << std::endl;
	}
}