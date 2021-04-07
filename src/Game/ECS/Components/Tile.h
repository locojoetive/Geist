#pragma once

#include <SDL.h>
#include "../ECS.h"
#include "Transform.h"

class Tile : public Component
{
public:
	Transform* transform;
	Sprite* sprite;
	SDL_Rect tileRect;
	int tileID;
	const char* path;

	Tile() = default;

	Tile(int x, int y, int w, int h, int id)
	{
		tileRect.x = x;
		tileRect.y = y;
		tileRect.w = w;
		tileRect.h = h;
		tileID = id;

		switch (tileID)
		{
		case 0:
			path = "assets/water.png";
			break;
		case 1:
			path = "assets/dirt.png";
			break;
		case 2:
			path = "assets/grass.png";
			break;
		default:
			break;
		}
	}

	void init() override
	{
		entity->addComponent<Transform>((float) tileRect.x, (float) tileRect.y, tileRect.w, tileRect.h, 1);
		transform = &entity->getComponent<Transform>();

		entity->addComponent<Sprite>(path);
		sprite = &entity->getComponent<Sprite>();
	}
};