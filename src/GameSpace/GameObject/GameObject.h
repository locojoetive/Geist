#pragma once

#include "../../Maf/Vector.h"
#include "../Game.h"

namespace GameSpace {
	class GameObject
	{
	public:
		GameObject(const char*, int, int);
		~GameObject();

		Maf::Vector* position;
		
		void Update();
		void Render();

	private:
		SDL_Texture* texture;
		SDL_Rect srcRect, destRect;
	};
}