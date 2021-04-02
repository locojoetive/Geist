#include "Vector.h"

namespace Maf {
	std::string Vector::toString() {
		return "P(" + std::to_string(X) + ", " + std::to_string(Y) + ")";
	}
}