#pragma once

#include <SDL.h>
#undef main
#include <SDL_image.h>
#include <iostream>
#include <vector>

class Collider2D;

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

	static void AddTile(int id, int x, int y);
	static SDL_Renderer* renderer;
	static SDL_Event event;
	static std::vector<Collider2D*> colliders;
private:
	int count = 0;
	bool isRunning = false;
	SDL_Window* window;
};