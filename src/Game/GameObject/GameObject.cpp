#include "TextureManager/TextureManager.h"

namespace GameSpace {
	GameObject::GameObject(const char* textureSrcPath, SDL_Renderer* ren, Maf::Vector* start)
	{
		renderer = ren;
		texture = TextureManager::LoadTexture(textureSrcPath, ren);
		position = *start;
	}

	void GameObject::Update() {
		position.X++;
		position.Y++;

		srcRect.h = 32;
		srcRect.w = 32;
		srcRect.x = 32;
		srcRect.y = 32;

		destRect.x = position.X;
		destRect.y = position.Y;
		destRect.w = srcRect.w * 2;
		destRect.h = srcRect.h * 2;
	}

	void GameObject::Render()
	{
		SDL_RenderCopy(renderer, texture, &srcRect, &destRect);
	}
}