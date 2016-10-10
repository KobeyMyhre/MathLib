#pragma once
#include "vec2.h"

union mat2
{
	float m[4];
	float mm[2][2];
	vec2 c[2];
};

//mat2 == mat2
//transpose(mat2)
//mat2 + mat2
//mat2 - mat2
// -mat2

//mat2 * float
//float * mat2
//mat2 * mat2
//mat2 * vec2

//determinant(mat2)
// inverse mat2
