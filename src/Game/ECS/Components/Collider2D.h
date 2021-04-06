#pragma once


#include <string>
#include <SDL.h>
#include "Components.h"

class Collider2D : public Component
{
public:
	SDL_Rect collider;
	std::string tag;

	Transform* transform;
	Collider2D(std::string _tag) 
	{
		tag = _tag;
	}
	void init() override
	{
		if (!entity->hasComponent<Transform>()) 
		{
			entity->addComponent<Transform>();
		}
		transform = &entity->getComponent<Transform>();
	}

	void update() override
	{
		collider.x = static_cast<int> (transform->position.X);
		collider.y = static_cast<int> (transform->position.Y);
		collider.w = transform->width * transform->scale;
		collider.h = transform->height * transform->scale;
	}
};