#pragma once

#include "../../../../Maf/Vector2D.h"
#include "../../../Game.h"

class GameObject
{
public:
	GameObject(const char*, int, int);
	~GameObject();

	Vector2D* position;
		
	void Update();
	void Render();

private:
	SDL_Texture* texture;
	SDL_Rect srcRect, destRect;
};