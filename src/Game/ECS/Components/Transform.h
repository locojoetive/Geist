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
		position = Vector2D();
	}

	Transform(float x, float y) {
		position = Vector2D(x, y);
	}

	void init() override
	{
		velocity = Vector2D(0,0);
	}

	void update() override
	{
		position.X += velocity.X * speed;
		position.Y += velocity.Y * speed;
		std::cout << position << " " << velocity << " " << speed << std::endl;
	}
};