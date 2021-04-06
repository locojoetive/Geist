#pragma once

#include "Components.h"
#include "../../TextureManager/TextureManager.h"
#include "../../../Maf/Vector2D.h"
#include <SDL.h>

class Sprite : public Component
{
private:
	Transform* transform = nullptr;
	SDL_Texture* texture;
	SDL_Rect srcRect, destRect;
public:
	Sprite() = default;
	Sprite(const char* path)
	{
		setTexture(path);
	}

	void setTexture(const char* path) 
	{
		texture = TextureManager::LoadTexture(path);
	}

	void init() override
	{
		transform = &entity->getComponent<Transform>();

		srcRect.x = srcRect.y = 0;
		srcRect.w = srcRect.h = 32;
		destRect.w = destRect.h = 64;
	}

	void update() override
	{
		destRect.x = (int) transform->position.X;
		destRect.y = (int) transform->position.Y;
	}

	void draw() override 
	{
		TextureManager::Draw(texture, srcRect, destRect);
	}
};