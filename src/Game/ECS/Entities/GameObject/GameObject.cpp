#include "../../../TextureManager/TextureManager.h"
#include "GameObject.h"

GameObject::GameObject(const char* textureSrcPath, int x, int y)
{
	texture = TextureManager::LoadTexture(textureSrcPath);
	position = new Vector2D(x, y);
		
	srcRect.h = 32;
	srcRect.w = 32;
	srcRect.x = 0;
	srcRect.y = 0;
		
	destRect.x = position->X;
	destRect.y = position->Y;
	destRect.w = srcRect.w * 2;
	destRect.h = srcRect.h * 2;
		
}

GameObject::~GameObject() {	}

void GameObject::Update() {
	position->X++;
	position->Y++;

	destRect.x = position->X;
	destRect.y = position->Y;
}

std::string toString(SDL_Rect rect) {
	std::string result = "P(" + std::to_string(rect.x) + ", " + std::to_string(rect.y) + ") " + " Size(" + std::to_string(rect.w) + ", " + std::to_string(rect.h) + ")";
	return result;
}

void GameObject::Render()
{
	SDL_RenderCopy(Game::renderer, texture, &srcRect, &destRect);
}
