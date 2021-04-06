#include "Collision2D.h"
#include <iostream>
bool Collision2D::AABB(const SDL_Rect& rectA, const SDL_Rect& rectB) 
{
	if (
		rectA.x + rectA.w >= rectB.x
		&& rectB.x + rectB.w >= rectA.x
		&& rectA.y + rectA.h >= rectB.y
		&& rectB.y + rectB.h >= rectA.y
	) {
		std::cout
			<< "LT1(" << rectA.x << ", " << rectA.y << ")"
			<< " RB1(" << (rectA.x + rectA.w) << ", " << (rectA.y + rectA.h) << ")"
			<< std::endl
			<< "LT2(" << rectB.x << ", " << rectB.y << ")"
			<< " RB2(" << (rectB.x + rectB.w) << ", " << (rectB.y + rectB.h) << ")"
			<< std::endl;

		return true;
	}
	return false;
}