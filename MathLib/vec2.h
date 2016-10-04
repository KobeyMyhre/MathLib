#pragma once
#include "Flops.h"
struct vec2 { float x, y; };

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

vec2 lerp(vec2 start, vec2 end, vec2 alpha);
vec2 quadBezier(vec2 a_A, vec2 a_B, vec2 a_C, vec2 a_t);
vec2 hermitspline(vec2 start, vec2 s_tan, vec2 end, vec2 e_tan, vec2 alpha);
vec2 cardinalSpline(vec2 point0, vec2 point1, vec2 point2, vec2 a, vec2 t);
vec2 catRomSpline(vec2 point0, vec2 point1, vec2 point2, vec2 t);