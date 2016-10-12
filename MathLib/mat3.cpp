#include "mat3.h"
#include "Flops.h"
#include <cmath>
vec3 mat3::operator[](unsigned idx) const
{
	return c[idx];
}

vec3 & mat3::operator[](unsigned idx)
{
	return c[idx];
}

mat3 mat3Identity()
{
	return mat3{ 1,0,0,
				 0,1,0,
				 0,0,1 };
}

bool operator==(const mat3 & A, const mat3 & B)
{
	return fequals(A.m[0], B.m[0]) &&
		fequals(A.m[1], B.m[1]) &&
		fequals(A.m[2], B.m[2]) &&
		fequals(A.m[3], B.m[3]) &&
		fequals(A.m[4], B.m[4]) &&
		fequals(A.m[5], B.m[5]) &&
		fequals(A.m[6], B.m[6]) &&
		fequals(A.m[7], B.m[7]) &&
		fequals(A.m[8], B.m[8]);
}

bool operator!=(const mat3 & A, const mat3 & B)
{
	/*return
		!fequals(A.m[0], B.m[0]) ||
		!fequals(A.m[1], B.m[1]) ||
		!fequals(A.m[2], B.m[2]) ||
		!fequals(A.m[3], B.m[3]);*/

	return !(A == B);
}

mat3 transpose(const mat3 & idx)
{
	mat3 temp = idx;


	
	temp.m[0] = idx.m[0];
	temp.m[1] = idx.m[3];
	temp.m[2] = idx.m[6];
	temp.m[3] = idx.m[1];
	temp.m[4] = idx.m[4];
	temp.m[5] = idx.m[7];
	temp.m[6] = idx.m[2];
	temp.m[7] = idx.m[5];
	temp.m[8] = idx.m[8];

	return idx;
}

mat3 operator+(const mat3 & A, const mat3 & B)
{
	return mat3{ A.m[0] + B.m[0],  A.m[1] + B.m[1],
		A.m[2] + B.m[2], A.m[3] + B.m[3], A.m[4] + B.m[4],  A.m[5] + B.m[5],
		A.m[6] + B.m[6], A.m[7] + B.m[7] , A.m[8] + B.m[8] };
}

mat3 operator-(const mat3 & A, const mat3 & B)
{
	return mat3{ A.m[0] - B.m[0],  A.m[1] - B.m[1],
		A.m[2] - B.m[2], A.m[3] - B.m[3], A.m[4] - B.m[4],  A.m[5] - B.m[5],
		A.m[6] - B.m[6], A.m[7] - B.m[7] , A.m[8] - B.m[8] };
}

mat3 operator*(const mat3 & A, float B)
{
	/*return mat3{ A.m[0] * B, A.m[1] * B,
		A.m[2] * B, A.m[3] * B, A.m[4] * B, A.m[5] * B,
		A.m[6] * B, A.m[7] * B , A.m[8] * B };*/
	return B*A;
}

mat3 operator*(float A, const mat3 & B)
{
	return{ B.m[0] * A,  B.m[1] * A,
		B.m[2] * A,B.m[3] * A, B.m[4] * A,  B.m[5] * A,
		B.m[6] * A,B.m[7] * A  ,B.m[8] * A };
	
}

mat3 operator*(const mat3 & A, const mat3 & B)
{
	return mat3{ ((A.m[0] * B.m[0]) + (A.m[3] * B.m[1]) + (A.m[6] * B.m[2])),
				 ((A.m[1] * B.m[0]) + (A.m[4] * B.m[1]) + (A.m[7] * B.m[2])),
				 ((A.m[2] * B.m[0]) + (A.m[5] * B.m[1]) + (A.m[8] * B.m[2])),

				((A.m[0] * B.m[3]) + (A.m[3] * B.m[4]) + (A.m[6] * B.m[5])),
				((A.m[1] * B.m[3]) + (A.m[4] * B.m[4]) + (A.m[7] * B.m[5])),
				((A.m[2] * B.m[3]) + (A.m[5] * B.m[4]) + (A.m[8] * B.m[5])),
		
				((A.m[0] * B.m[6]) + (A.m[3] * B.m[7]) + (A.m[6] * B.m[8])),			
				((A.m[1] * B.m[6]) + (A.m[4] * B.m[7]) + (A.m[7] * B.m[8])),						
				((A.m[2] * B.m[6]) + (A.m[5] * B.m[7]) + (A.m[8] * B.m[8])),
	};
}

vec3 operator*(const mat3 & A, const vec3 & B)
{
	return vec3{ ((A.m[0] * B.x) + (A.m[3] * B.y) + (A.m[6] * B.z)),
				 ((A.m[1] * B.x) + (A.m[4] * B.y) + (A.m[7] * B.z)),
				 ((A.m[2] * B.x) + (A.m[5] * B.y) + (A.m[8] * B.z)),
				
	};
}

mat3 scale(float w, float h)
{
	return {     w, 0, 0,
				 0, h, 0,
				 0, 0, 1     };
}

mat3 translate(float x, float y)
{
	return mat3 { 1, 0, 0,
				  0, 1, 0,
				  x, y, 1,};
}

mat3 rotation(float a)
{
	return mat3{ cos(a), sin(a), 0,
				-sin(a), cos(a), 0,
				0     , 0     , 1 };
}



mat3 operator-(const mat3 & v)
{
	return v*-1;
	
	/*	{
		-v.m[0],-v.m[1],-v.m[2],-v.m[3]
		- v.m[4],-v.m[5],-v.m[6],-v.m[7] ,-v.m[8]
		};*/
}

mat3 inverse(const mat3 &D)
{
	
	mat3 retval = D;

	retval[0] = cross(D[1], D[2]);
	retval[1] = cross(D[2], D[0]);
	retval[2] = cross(D[0], D[1]);

	return 1 / determinate(D) * transpose(retval);
}
float determinate(const mat3 &D)
{
	return float ((D.m[0] * D.m[4] * D.m[8]) +
			(D.m[3] * D.m[7] * D.m[2]) + 
			(D.m[6] * D.m[1] * D.m[5]) - 
			(D.m[6] * D.m[4] * D.m[2]) - 
			(D.m[3] * D.m[1] * D.m[8]) - 
			(D.m[0] * D.m[7] * D.m[5]));
}