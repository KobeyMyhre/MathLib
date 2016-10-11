#pragma once
#include "vec2.h"

union mat2
{
	float m[4];
	float mm[2][2];
	vec2 c[2];

	vec2 operator[](unsigned idx) const;
	vec2 &operator[](unsigned idx);
};
mat2 mat2Identity();
mat2 transpose(const mat2 &idx);

bool operator==(const mat2 &A, const mat2 &B);
bool operator!=(const mat2 &A, const mat2 &B);

mat2 operator+(const mat2 &A, const mat2 &B);
mat2 operator-(const mat2 & A, const mat2 & B);
mat2 operator-(const mat2 &v);

mat2 operator*(const mat2 &A, float B);
mat2 operator*(float A, const mat2 &B);
mat2 operator*(const mat2 &A, const mat2 &B);
vec2 operator*(const mat2 &A, const vec2 &B);

float determinate(const mat2 &d);
mat2 inverse(const mat2 &v);


//mat2[unsigned]
//mat2 == mat2 ----------
//transpose(mat2)
//mat2 + mat2------------
//mat2 - mat2------------
// -mat2-----------------

//mat2 * float-----------
//float * mat2-----------
//mat2 * mat2------------
//mat2 * vec2------------

//determinant(mat2)
// inverse mat2
