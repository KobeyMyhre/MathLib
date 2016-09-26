#include "vec2.h"

bool operator==(const vec2 & lhs, const vec2 & rhs)
{
	return lhs.x = rhs.x && lhs.y == rhs.y;
}
