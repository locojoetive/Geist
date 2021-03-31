#pragma once

namespace Maf {

	struct Vector {
		int X;
		int Y;
		Vector() : X(0), Y(0) {};
		Vector(int x, int y) : X(x), Y(y) {};
	};

}