#pragma once
#include "ECS.h"
#include "src/Maf/Vector.h"

class Transform : public Component
{
public:
	Maf::Vector position;

	void init() override
	{
		position = Maf::Vector();
	}

	void update() override
	{
		position.X++;
		position.Y++;
	}
};