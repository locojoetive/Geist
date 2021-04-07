#pragma once
#include "Components.h"
#include "../../../Maf/Vector2D.h"

class Transform : public Component
{
public:
	Vector2D position;
	Vector2D velocity;

	float speed = 3.0f;

	int height = 32;
	int width = 32;
	int scale = 1;

	Transform() {
		position.Zero();
	}

	Transform(int _scale) {
		position.Zero();
		scale = _scale;
	}

	Transform(float x, float y) {
		position = Vector2D(x, y);
	}

	Transform(float x, float y, int _width, int _height, int _scale) {
		position = Vector2D(x, y);
		height = _height;
		width = _width;
		scale = _scale;
	}

	void init() override
	{
		velocity.Zero();
	}

	void update() override
	{
		position.X += velocity.X * speed;
		position.Y += velocity.Y * speed;
	}
};