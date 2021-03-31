#pragma once

#include "../../Game.h"

namespace GameSpace {

	class TextureManager {
	public:
		static SDL_Texture* LoadTexture(const char* fileName, SDL_Renderer* ren);
	};

}