#include "Game.h"
#include "TextureManager.h"

SDL_Texture* playerTex;
SDL_Rect sourceRectangle, destinationRectangle;

Game::Game() {
	window = nullptr;
	renderer = nullptr;
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
	playerTex = TextureManager::LoadTexture("assets/sword/sword_0.png", renderer);
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
	destinationRectangle.h = 64;
	destinationRectangle.w = 64;
	destinationRectangle.x = count;

	std::cout << count << std::endl;
}

void Game::render()
{
	SDL_RenderClear(renderer);
	
	// Sword
	SDL_RenderCopy(renderer, playerTex, NULL, &destinationRectangle);

	SDL_RenderPresent(renderer);
}

void Game::clean()
{
	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);
	SDL_Quit();
	std::cout << "Game Cleaned" << std::endl;
}
