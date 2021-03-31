#pragma once

#include "../../Maf/Vector.h"
#include "../Game.h"

namespace GameSpace {
	class GameObject
	{
	public:
		GameObject(const char*, SDL_Renderer*, Maf::Vector*);
		~GameObject();
		void Update();
		void Render();

	private:
		Maf::Vector position;
		SDL_Texture* texture;
		SDL_Rect srcRect, destRect;
		SDL_Renderer* renderer;
	};
}