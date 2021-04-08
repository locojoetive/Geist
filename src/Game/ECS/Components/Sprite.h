#pragma once

#include <SDL.h>
#include <map>
#include "../../../Maf/Vector2D.h"
#include "../../TextureManager/TextureManager.h"
#include "Components.h"
#include "Animation.h"

class Sprite : public Component
{
private:
	Transform* transform = nullptr;
	SDL_Texture* texture;
	SDL_Rect srcRect, destRect;

	bool animated = false;
	int frames = 0;
	int speed = 100;
public:
	int animationIndex = 0;

	std::map<const char*, Animation> animations;
	SDL_RendererFlip spriteFlip = SDL_FLIP_NONE;

	Sprite() = default;
	Sprite(const char* path)
	{
		setTexture(path);
	}
	
	Sprite(const char* path, bool isAnimated)
	{
		animated = isAnimated;

		Animation idle = Animation(0, 4, 100);
		Animation walk = Animation(1, 4, 100);

		animations.emplace("Idle", idle);
		animations.emplace("Walk", walk);

		Play("Idle");
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
		if (animated)
		{
			srcRect.x = srcRect.w * static_cast<int>((SDL_GetTicks() / speed) % frames);
		}

		srcRect.y = animationIndex * transform->height;

		destRect.x = static_cast<int>(transform->position.X);
		destRect.y = static_cast<int>(transform->position.Y);
		destRect.w = transform->width * transform->scale;
		destRect.h = transform->height* transform->scale;
	}

	void draw() override 
	{
		TextureManager::Draw(texture, srcRect, destRect, spriteFlip);
	}

	void Play(const char* animationName)
	{
		frames = animations[animationName].frames;
		animationIndex = animations[animationName].index;
		speed = animations[animationName].speed;
	}
};