#include "TextureManager.h"

SDL_Texture* TextureManager::LoadTexture(const char* texturePath) {
	SDL_Surface* tmpSurface = IMG_Load(texturePath);
	SDL_Texture* texture = SDL_CreateTextureFromSurface(Game::renderer, tmpSurface);
	SDL_FreeSurface(tmpSurface);
	return texture;
}
	
void TextureManager::Draw(SDL_Texture* texture, SDL_Rect src, SDL_Rect dest)
{
	SDL_RenderCopy(Game::renderer, texture, &src, &dest);
}