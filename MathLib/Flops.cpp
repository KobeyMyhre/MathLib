#include "Flops.h"
#include <cmath>
#include <cfloat>
#define _USE_MATH_DEFINES
#include "math.h"
bool fequals(float lhs, float rhs)
{
	if ( fabs(lhs - rhs) < .00001f )
	{
		return true;
	}
	else
	{
		return false;
	}
}

float deg2rad(float deg)
{
	return (deg * M_PI) / 180;
}

float rad2deg(float rad)
{
	return (rad * 180) / M_PI;
}
//////////////////////////
// Basic Curving Stuff
float LinearHalf(float x)
{
	return 0.5f*x;
}
float growFast(float x)
{
	return x*x;
}

float growFaster(float x)
{
	return 1 - (1 - x)*(1 -x);
}

float TriBS(float x)
{
	return abs(2 * ((x) - 1) + 1);
}
float bounce(float x)
{
	return abs(cos(x * 10)*(1 - x));
}

float bounceflip(float x)
{
	return 1- bounce(x);
}

float parabolaflip(float x)
{
	return -4*(x - .4)*(x - .4) + 0;
}

float lerp(float start, float end, float alpha)
{
	return (1 - alpha)*start + (alpha)*end;

	return alpha*(end - start) + start;

}

float quadBezier(float a_A, float a_B, float a_C, float a_t)
{
	float mid1 = lerp(a_A, a_B, a_t);
	float mid2 = lerp(a_B, a_C, a_t);
	return lerp(mid1, mid2, a_t);
}

float hermitspline(float point0, float point1, float tangent0, float tangent1, float t)
{
	float tsq = t * t;
	float tcub = tsq * t;

	float h00 = (2 * tcub) - (3 * tsq) + 1;
	float h01 = (-2 * tcub) + (3 * tsq);
	float h10 = (tcub) - (2 * tsq) + t;
	float h11 = tcub - tsq;
	float point = h00 * point0 + h10 * point1 + h01 * tangent0 + h11 * tangent1;

	return point;
}

float cardinalSpline(float point0, float point1, float point2, float a, float t)
{
	float s_tan = ((point1 - point0) * a),
		etain = (point2 - point1) * a;

	return hermitspline(point0, s_tan, point2, etain, t);
	/*float tangent0 = (point1 - point0) * a;
	float tangent1 = (point2 - point1) * a;

	float tsq = t * t;
	float tcub = tsq * t;

	float h00 = 2 * tcub - 3 * tsq + 1;
	float h01 = -2 * tcub + 3 * tsq;
	float h10 = tcub - 2 * tsq + t;
	float h11 = tcub - tsq;

	float point = h00 * point0 + h10 * tangent0 + h01 * point1 + h11 * tangent1;

	return point;*/
}

float catRomSpline(float point0, float point1, float point2, float t)
{

	return cardinalSpline(point0, point1, point2, .5f, t);
	/*float tangent0 = (point1 - point0) * .5;
	float tangent1 = (point2 - point1) * .5;

	float tsq = t * t;
	float tcub = tsq * t;

	float h00 = 2 * tcub - 3 * tsq + 1;
	float h01 = -2 * tcub + 3 * tsq;
	float h10 = tcub - 2 * tsq + t;
	float h11 = tcub - tsq;

	float point = h00 * point0 + h10 * tangent0 + h01 * point1 + h11 * tangent1;

	return point;*/
}

