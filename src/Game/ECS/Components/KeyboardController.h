#pragma once

#include "../../Game.h"
#include "../ECS.h"
#include "Components.h"

class KeyboardController : public Component
{
public:
	Transform* transform;

	void init() override
	{
		transform = &entity->getComponent<Transform>();
	}

	void update() override
	{
		if (Game::event.type == SDL_KEYDOWN)
		{
			switch (Game::event.key.keysym.sym)
			{
			case SDLK_w:
				transform->velocity.Y = -1;
				break;
			case SDLK_s:
				transform->velocity.Y = 1;
				break;
			case SDLK_d:
				transform->velocity.X = 1;
				break;
			case SDLK_a:
				transform->velocity.X = -1;
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
				break;
			case SDLK_s:
				transform->velocity.Y = 0;
				break;
			case SDLK_d:
				transform->velocity.X = 0;
				break;
			case SDLK_a:
				transform->velocity.X = 0;
				break;
			default:
				break;
			}
		}
	}
};