#include "../Maf/Vector2D.h"
#include "Game.h"
#include "Collision2D/Collision2D.h"
#include "ECS/Components/Components.h"
#include "Map/Map.h"
#include "TextureManager/TextureManager.h"

Map* map;
Manager manager;

SDL_Renderer* Game::renderer = nullptr;
SDL_Event Game::event;

std::vector<Collider2D*> Game::colliders;

auto& player(manager.addEntity());
auto& wall(manager.addEntity());

auto& tile0(manager.addEntity());
auto& tile1(manager.addEntity());
auto& tile2(manager.addEntity());

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

		tile0.addComponent<Tile>(200, 200, 32, 32, 0);
		
		tile1.addComponent<Tile>(250, 250, 32, 32, 1);
		tile1.addComponent<Collider2D>("dirt");

		tile2.addComponent<Tile>(150, 150, 32, 32, 2);
		tile2.addComponent<Collider2D>("grass");
		
		player.addComponent<Transform>(2);
		player.addComponent<Sprite>("assets/sword.png");
		player.addComponent<KeyboardController>();
		player.addComponent<Collider2D>("player");
		
		wall.addComponent<Transform>(300, 300, 300, 20, 1);
		wall.addComponent<Sprite>("assets/dirt.png");
		wall.addComponent<Collider2D>("wall");
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

	for (auto collider : colliders)
	{
		Collision2D::AABB(player.getComponent<Collider2D>(), *collider);
	}

}

void Game::render()
{
	SDL_RenderClear(renderer);
	// map->DrawMap();

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