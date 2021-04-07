#include "Game.h"
#include "TextureManager/TextureManager.h"
#include "Map/Map.h"
#include "ECS/Components/Components.h"
#include "../Maf/Vector2D.h"
#include "../Collision2D.h"

Map* map;
Manager manager;

SDL_Renderer* Game::renderer = nullptr;
SDL_Event Game::event;

auto& player(manager.addEntity());
auto& wall(manager.addEntity());

Game::Game() {}

Game::~Game() {}

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
		map = new Map();

		wall.addComponent<Transform>(300, 300, 300, 20, 1);
		wall.addComponent<Sprite>("assets/dirt.png");
		wall.addComponent<Collider2D>("wall");

		player.addComponent<Transform>(2);
		player.addComponent<Sprite>("assets/sword.png");
		player.addComponent<KeyboardController>();
		player.addComponent<Collider2D>("player");



	}
	else {
		isRunning = false;
	}

}

void Game::handleEvents()
{
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
	manager.refresh();
	manager.update();

	if (Collision2D::AABB(player.getComponent<Collider2D>().collider, wall.getComponent<Collider2D>().collider))
	{
		player.getComponent<Transform>().velocity * -1;
		// std::cout << "Wall Hit!!!" << std::endl;
	}
}

void Game::render()
{
	SDL_RenderClear(renderer);
		
	map->DrawMap();
	manager.draw();
	SDL_RenderPresent(renderer);
}

	  
void Game::clean()
{
	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);
	SDL_Quit();
	std::cout << "Game Cleaned" << std::endl;
}