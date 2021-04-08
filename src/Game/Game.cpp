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

enum groupLabels : std::size_t
{
	groupMap,
	groupPlayers,
	groupEnemies,
	groupColliders
};

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

		Map::LoadMap("assets/p16x16.map", 16, 16);
		
		player.addComponent<Transform>(2);
		player.getComponent<Transform>().width = 16;
		player.getComponent<Transform>().height = 16;
		player.addComponent<Sprite>("assets/ghost_spritesheet.png", true);
		player.addComponent<KeyboardController>();
		player.addComponent<Collider2D>("player");
		player.addGroup(groupPlayers);

		/*
		wall.addComponent<Transform>(300, 300, 300, 20, 1);
		wall.addComponent<Sprite>("assets/dirt.png");
		wall.addComponent<Collider2D>("wall");
		wall.addGroup(groupMap);
		*/
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

auto& tiles(manager.getGroup(groupMap));
auto& players(manager.getGroup(groupPlayers));
auto& enemies(manager.getGroup(groupEnemies));

void Game::render()
{
	SDL_RenderClear(renderer);
	for (auto& t : tiles)
	{
		t->draw();
	}
	for (auto& p : players)
	{
		p->draw();
	}
	for (auto& e : enemies)
	{
		e->draw();
	}
	SDL_RenderPresent(renderer);
}

void Game::clean()
{
	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);
	SDL_Quit();
	std::cout << "Game Cleaned" << std::endl;
}

void Game::AddTile(int id, int x, int y)
{
	auto& tile(manager.addEntity());
	tile.addComponent<Tile>(x, y, 32, 32, id);
	tile.addGroup(groupMap);
}