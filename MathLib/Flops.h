#pragma once
bool fequals(float lhs, float rhs);

float deg2rad(float deg);
float rad2deg(float rad);

//////////////////////////
float LinearHalf(float x);

float growFast(float x);

float growFaster(float x);

float TriBS(float x);

float bounce(float x);
float bounceflip(float x);

float parabolaflip(float x);

float lerp(float start, float end, float alpha);
float quadBezier(float a_A, float a_B, float a_C, float a_t);
float hermitspline(float start, float s_tan, float end, float e_tan, float alpha);
float cardinalSpline(float point0, float point1, float point2, float a, float t);
float catRomSpline(float point0, float point1, float point2, float t);