#pragma once

#include <SDL.h>
#include "../../../Maf/Vector2D.h"
#include "../../TextureManager/TextureManager.h"
#include "Components.h"

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
	~Sprite() 
	{
		SDL_DestroyTexture(texture);
	}

	void setTexture(const char* path) 
	{
		texture = TextureManager::LoadTexture(path);
	}

	void init() override
	{
		transform = &entity->getComponent<Transform>();

		srcRect.x = srcRect.y = 0;
		srcRect.w = transform->width;
		srcRect.h = transform->height;
	}

	void update() override
	{
		destRect.x = static_cast<int>(transform->position.X);
		destRect.y = static_cast<int>(transform->position.Y);
		destRect.w = transform->width * transform->scale;
		destRect.h = transform->height* transform->scale;
	}

	void draw() override 
	{
		TextureManager::Draw(texture, srcRect, destRect);
	}
};