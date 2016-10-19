#include "vec2.h"
#include "Flops.h"
#include <cmath>
vec2 operator+(const vec2 & lhs, const vec2 & rhs)
{
	return vec2{lhs.x + rhs.x, lhs.y + rhs.y};
}

vec2 operator-(const vec2 & lhs, const vec2 & rhs)
{
	return vec2{ lhs.x + rhs.x, lhs.y + rhs.y };
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
float angle(const vec2 &v)
{
	return atan2f(v.y,v.x);
}

vec2 fromAngle(float a)
{
	return vec2{cos(a), sin(a)};
}

vec2 lerp(const vec2 &start, const vec2 &end, float alpha)
{
	vec2 retval;
	retval.x = lerp(start.x, end.x, alpha);
	retval.y = lerp(start.y, end.y, alpha);
	return retval;

}
vec2 quadBezier(vec2 &start, vec2 &mid, vec2 &end, float alpha)
{
	vec2 retval;
	retval.x = quadBezier(start.x, mid.x, end.x, alpha);
	retval.y = quadBezier(start.y, mid.y, end.y, alpha);
	return retval;
}
vec2 hermitspline(vec2 &start, vec2 &end, vec2 &s_tan, vec2 &e_tan, float alpha)
{
	vec2 retval;
	retval.x = hermitspline(start.x, end.x, s_tan.x, e_tan.x, alpha);
	retval.y = hermitspline(start.y, end.y, s_tan.y, e_tan.y, alpha);
	return retval;
}
vec2 cardinalSpline(vec2 &start, vec2 &mid, vec2 &end, float tightness, float alpha)
{
	vec2 retval;
	retval.x = cardinalSpline(start.x, mid.x, end.x, tightness, alpha);
	retval.y = cardinalSpline(start.y, mid.y, end.y, tightness, alpha);
	return retval;
}
vec2 catRomSpline(vec2 &start, vec2 &mid, vec2 &end, float alpha)
{
	vec2 retval;
	retval.x = catRomSpline(start.x, mid.x, end.x, alpha);
	retval.y = catRomSpline(start.y, mid.y, end.y, alpha);
	return retval;
}

float vec2::operator[](unsigned idx) const
{
	return v[idx];
}

float & vec2::operator[](unsigned idx)
{
	return v[idx];
}
