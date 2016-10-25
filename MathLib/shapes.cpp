#include "shapes.h"

circle operator*(const mat3 & T, const circle & C)
{
	circle retval;

	retval.pos = (T * vec3{ C.pos.x, C.pos.y, 1 }).xy;
	
	float yRad = magnitude(T * vec3{C.radius , 0, 0});
	float xRad = magnitude(T * vec3{0,C.radius,0});

	retval.radius = xRad > yRad ? xRad : yRad;

	return retval;
}

bool operator==(const circle &A, const circle &B)
{
	return A.pos == B.pos && fequals(A.radius, B.radius);
}

AABB operator*(const mat3 & T, const AABB & B)
{
	AABB retval = B;

	retval.pos = (T * vec3{ B.pos.x, B.pos.y, 1 }).xy;

	float xhe = magnitude(T * vec3{ retval.he.x , 0, 0 });
	float yhe = magnitude(T * vec3{ 0,retval.he.y,0 });

	retval.he = { xhe, yhe };

	return retval;
}

vec2 AABB::min() const
{
	return pos - he;
}

vec2 AABB::max() const
{
	return pos + he;
}
