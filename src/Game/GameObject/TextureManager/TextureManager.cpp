#include "TextureManager.h"

namespace GameSpace {
	SDL_Texture* TextureManager::LoadTexture(const char* texturePath, SDL_Renderer* renderer) {
		SDL_Surface* tmpSurface = IMG_Load(texturePath);
		SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, tmpSurface);
		SDL_FreeSurface(tmpSurface);
		return texture;
	}
}