#pragma once
#include "Flops.h"
union vec2 
{
	float v[2];
	struct
	{
		float x, y;
	};
	float operator[](unsigned idx) const;
	float &operator[](unsigned idx) ;
	
};

vec2 operator+(const vec2 &lhs, const vec2 &rhs);
vec2 operator-(const vec2 & lhs, const vec2 & rhs);

vec2 operator*(const vec2 &lhs, const vec2 &rhs);
vec2 operator/(const vec2 & lhs, const vec2 & rhs);

vec2 operator*(const vec2 &lhs, float rhs);
vec2 operator*(float lhs, const vec2 &rhs);


vec2 operator/(const vec2 &lhs, float rhs);

vec2 operator-(const vec2 &v);

vec2 &operator+=(vec2 &lhs, const vec2 &rhs);
vec2 &operator-=(vec2 &lhs, const vec2 &rhs);
vec2 &operator*=(vec2 &lhs, const vec2 &rhs);
vec2 &operator/=(vec2 &lhs, const vec2 &rhs);

bool operator==(const vec2 &lhs, const vec2 &rhs);
bool operator!=(const vec2 &lhs, const vec2 &rhs);

float magnitude(const vec2 &v);

vec2 normal(const vec2 &v);

float dot(const vec2 &rhs, const vec2 &lhs);
float angleBetween(const vec2 &rhs, const vec2 &lhs);

vec2 perp(const vec2 &v);

float angle(const vec2 &v);

vec2 fromAngle(float a);

vec2 lerp(const vec2 &start, const vec2 &end, float alpha);
vec2 quadBezier(vec2 &start, vec2 &mid, vec2 &end, float alpha);
vec2 hermitspline(vec2 &start, vec2 &s_tan, vec2 &end, vec2 &e_tan, float alpha);
vec2 cardinalSpline(vec2 &start, vec2 &mid, vec2 &end, float tightness, float alpha);
vec2 catRomSpline(vec2 &start, vec2 &mid, vec2 &end, float alpha);