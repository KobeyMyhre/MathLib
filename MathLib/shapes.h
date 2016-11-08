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
bool operator==(const AABB &A, const AABB &B);

struct plane 
{
	vec2 pos, dir;
};
plane  operator*(const mat3 & T, const plane  &C);
bool operator==(const plane &A, const plane &B);

struct ray 
{

};
ray  operator*(const mat3 &T, const ray  &B);

struct hull
{
	
	vec2 vertices[16];
	vec2 normals[16];
	unsigned int size;

	//assume a CW winding order
	//evalutate each normal 
	hull(const vec2 *vertices, unsigned vsize);
	hull() ;
};

hull operator*(const mat3 & T, const hull &C);
bool operator==(const hull &A, const hull &B);