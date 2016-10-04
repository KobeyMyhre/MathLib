#include "vec2.h"
#include "Flops.h"
#include <cmath>
vec2 operator+(const vec2 & lhs, const vec2 & rhs)
{
	return vec2{lhs.x + rhs.x, lhs.y + rhs.y};
}

vec2 operator-(const vec2 & lhs, const vec2 & rhs)
{
	return vec2{ lhs.x - rhs.x, lhs.y - rhs.y };
}

vec2 operator*(const vec2 & lhs, const vec2 & rhs)
{
	return vec2{ lhs.x * rhs.x, lhs.y * rhs.y };
}
vec2 operator/(const vec2 & lhs, const vec2 & rhs)
{
	return vec2{ lhs.x / rhs.x, lhs.y / rhs.y };
}


vec2 operator*(const vec2 &lhs, float rhs)
{
	return{ lhs.x * rhs, lhs.y * rhs };
}
vec2 operator*( float lhs, const vec2 &rhs)
{
	return{ rhs.x * lhs, rhs.x *lhs };
}

vec2 operator/(const vec2 &lhs, float rhs)
{
	return{ lhs.x / rhs, lhs.y / rhs };
}


vec2 operator-(const vec2 & v)
{
	return vec2{ -v.x, -v.y };
}

vec2 & operator+=(vec2 & lhs, const vec2 & rhs)
{
	return lhs = lhs + rhs;
}

vec2 & operator-=(vec2 & lhs, const vec2 & rhs)
{
	return lhs = lhs - rhs;
}

vec2 & operator*=(vec2 & lhs, const vec2 & rhs)
{
	return lhs = lhs * rhs;
}

vec2 & operator/=(vec2 & lhs, const vec2 & rhs)
{
	return lhs = lhs / rhs;
}

bool operator==(const vec2 &lhs, const vec2 &rhs)
{
	return fequals(lhs.x, rhs.x) && fequals(lhs.y, rhs.y);
}

bool operator!=(const vec2 &lhs, const vec2 &rhs)
{
	return lhs.x != rhs.x && lhs.y != rhs.y;
}

float magnitude(const vec2 & v)
{
	return (sqrt((v.x*v.x) + (v.y * v.y)));
}

vec2 normal(const vec2 & v)
{
	return (v / (sqrt((v.x*v.x) + (v.y * v.y))));
}

float dot(const vec2 & rhs, const vec2 & lhs)
{
	return ((lhs.x * rhs.x) + (lhs.y * rhs.y));
}

float angleBetween(const vec2 & rhs, const vec2 & lhs)
{
	return acos(dot(normal(rhs), normal(lhs)));
}

vec2 perp(const vec2 & v)
{
	return vec2{v.y, -v.x};
}

// tan(a) = Y/X
// atan(tan(a)) = atan(Y/X)
// a = atan(Y/X)
float angle(const vec2 & v)
{
	return atan2f(v.y,v.x);
}

vec2 fromAngle(float a)
{
	return vec2{cos(a), sin(a)};
}

vec2 lerp(vec2 &start, vec2 &end, float alpha)
{
	return (1 - alpha)*start + (alpha)*end;

	return alpha*(end - start) + start;

}

vec2 quadBezier(vec2 &a_A, vec2 &a_B, vec2 a_C, float a_t)
{
	vec2 mid1 = lerp(a_A, a_B, a_t);
	vec2 mid2 = lerp(a_B, a_C, a_t);
	return lerp(mid1, mid2, a_t);
}

vec2 hermitspline(vec2 &point0, vec2 &point1, vec2 &tangent0, vec2 &tangent1, float t)
{
	float tsq = t * t;
	float tcub = tsq * t;

	float h00 = 2 * tcub - 3 * tsq + 1;
	float h01 = -2 * tcub + 3 * tsq;
	float h10 = tcub - 2 * tsq + t;
	float h11 = tcub - tsq;
	vec2 point = h00 * point0 + h10 * tangent0 + h01 * point1 + h11 * tangent1;

	return point;
}

vec2 cardinalSpline(vec2 &point0, vec2 &point1, vec2 &point2, vec2 &a, float t)
{
	vec2 tangent0 = (point1 - point0) * a;
	vec2 tangent1 = (point2 - point1) * a;

	float tsq = t * t;
	float tcub = tsq * t;

	float h00 = 2 * tcub - 3 * tsq + 1;
	float h01 = -2 * tcub + 3 * tsq;
	float h10 = tcub - 2 * tsq + t;
	float h11 = tcub - tsq;

	vec2 point = h00 * point0 + h10 * tangent0 + h01 * point1 + h11 * tangent1;

	return point;
}

vec2 catRomSpline(vec2 &point0, vec2 &point1, vec2 &point2, float t)
{
	vec2 tangent0 = (point1 - point0) * .5;
	vec2 tangent1 = (point2 - point1) * .5;

	float tsq = t * t;
	float tcub = tsq * t;

	float h00 = 2 * tcub - 3 * tsq + 1;
	float h01 = -2 * tcub + 3 * tsq;
	float h10 = tcub - 2 * tsq + t;
	float h11 = tcub - tsq;

	vec2 point = h00 * point0 + h10 * tangent0 + h01 * point1 + h11 * tangent1;

	return point;
}