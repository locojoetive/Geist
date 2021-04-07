#include "../ECS/Components/Collider2D.h"
#include "Collision2D.h"
#include <iostream>

bool Collision2D::AABB(const SDL_Rect& rectA, const SDL_Rect& rectB) 
{
	return rectA.x + rectA.w >= rectB.x
		&& rectB.x + rectB.w >= rectA.x
		&& rectA.y + rectA.h >= rectB.y
		&& rectB.y + rectB.h >= rectA.y;
}

bool Collision2D::AABB(const Collider2D& colliderA, const Collider2D& colliderB)
{
	if (AABB(colliderA.collider, colliderB.collider))
	{
		std::cout << colliderA.tag << " hit: " << colliderB.tag << std::endl;
		return true;
	}

	return false;
}