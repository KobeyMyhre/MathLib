#pragma once
#include "mat3.h"

struct circle
{
	vec2 pos;
	float radius;

};

circle operator*(const mat3 &T, const circle &C);
bool operator==(const circle &A, const circle &B);

struct AABB
{
	vec2 pos, he;
	vec2 min() const;
	vec2 max() const; // top right corner


};
AABB operator*(const mat3 &T, const AABB &B);

struct plane 
{

};

struct ray 
{

};

struct hull
{


};



plane  operator*(const mat3 & T, const plane  &C);
ray  operator*(const mat3 &T, const ray  &B);
hull operator*(const mat3 & T, const hull &C);
