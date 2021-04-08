#pragma once

#include "../../Game.h"
#include "../ECS.h"
#include "Components.h"

class KeyboardController : public Component
{
public:
	Transform* transform;
	Sprite* sprite;
	void init() override
	{
		transform = &entity->getComponent<Transform>();
		sprite = &entity->getComponent<Sprite>();
	}

	void update() override
	{
		if (Game::event.type == SDL_KEYDOWN)
		{
			switch (Game::event.key.keysym.sym)
			{
			case SDLK_w:
				transform->velocity.Y = -1;
				sprite->Play("Walk");
				break;
			case SDLK_s:
				transform->velocity.Y = 1;
				sprite->Play("Walk");
				break;
			case SDLK_d:
				transform->velocity.X = 1;
				sprite->Play("Walk");
				sprite->spriteFlip = SDL_FLIP_NONE;
				break;
			case SDLK_a:
				transform->velocity.X = -1;
				sprite->Play("Walk");
				sprite->spriteFlip = SDL_FLIP_HORIZONTAL;
				break;
			default:
				break;
			}
		}

		if (Game::event.type == SDL_KEYUP)
		{
			switch (Game::event.key.keysym.sym)
			{
			case SDLK_w:
				transform->velocity.Y = 0;
				sprite->Play("Idle");
				break;
			case SDLK_s:
				transform->velocity.Y = 0;
				sprite->Play("Idle");
				break;
			case SDLK_d:
				transform->velocity.X = 0;
				sprite->Play("Idle");
				break;
			case SDLK_a:
				transform->velocity.X = 0;
				sprite->Play("Idle");
				break;
			default:
				break;
			}
		}
	}
};