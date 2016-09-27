#include "Flops.h"
#include <cmath>
bool fequals(float lhs, float rhs)
{
	if ( fabs(lhs - rhs) < 0.0000001)
	{
		return true;
	}
}

float deg2rad(float deg)
{
	return deg * 3.14 / 100;
}

float rad2deg(float rad)
{
	return rad * 100 / 3.14;
}
