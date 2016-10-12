#include "mat2.h"

vec2 mat2::operator[](unsigned idx) const
{
	return c[idx];
}

vec2 & mat2::operator[](unsigned idx)
{
	return c[idx];
}

mat2 mat2Identity()
{
	return mat2{ 1,0,0,1 };
}

bool operator==(const mat2 & A, const mat2 & B)
{
	return fequals(A.m[0], B.m[0]) &&
			fequals(A.m[1], B.m[1]) &&
			fequals(A.m[2], B.m[2]) &&
			fequals(A.m[3], B.m[3]);
}

bool operator!=(const mat2 & A, const mat2 & B)
{
	return 
		!fequals(A.m[0], B.m[0]) ||
		!fequals(A.m[1], B.m[1]) ||
		!fequals(A.m[2], B.m[2]) ||
		!fequals(A.m[3], B.m[3]);

	/*return !(A == B);*/
}

mat2 transpose(const mat2 & idx)
{

	
	mat2 retval = idx;


	retval.mm[1][0] = idx.mm[0][1];
	retval.mm[0][1] = idx.mm[1][0];

	return idx;
}

mat2 operator+(const mat2 & A, const mat2 & B)
{
	return mat2{ A.m[0] + B.m[0],  A.m[1] + B.m[1],
				A.m[2] + B.m[2], A.m[3] + B.m[3] };
}

mat2 operator-(const mat2 & A, const mat2 & B)
{
	return mat2{ A.m[0] - B.m[0],  A.m[1] - B.m[1],
		A.m[2] - B.m[2], A.m[3] - B.m[3] };
}

mat2 operator*(const mat2 & A, float B)
{
	return mat2{ A.m[0] * B, A.m[1] * B,
				A.m[2] * B, A.m[3] * B };
}

mat2 operator*(float A, const mat2 & B)
{
	return{ B.m[0] * A,  B.m[1] * A,
				B.m[2] * A,B.m[3] * A };
}

mat2 operator*(const mat2 & A, const mat2 & B)
{
	return mat2{ ((A.m[0] * B.m[0]) + (A.m[2] * B.m[1])),
				 ((A.m[0] * B.m[2]) + (A.m[2] * B.m[3])),
				 ((A.m[1] * B.m[0]) + (A.m[3] * B.m[1])),
				 ((A.m[1] * B.m[2]) + (A.m[3] * B.m[3]))};
}

vec2 operator*(const mat2 & A, const vec2 & B)
{
	return vec2{ ((A.m[0] * B.x) + (A.m[2] * B.x)),
				 ((A.m[1] * B.y) + (A.m[3] * B.y)),
				 };
}

mat2 operator-(const mat2 & v)
{
	return mat2{ -v.m[0],-v.m[1],-v.m[2],-v.m[3] };
}

mat2 inverse(const mat2 &D)
{
	/*mat2 temp;
	temp.m[0] = temp.m[3];
	temp.m[1] = -temp.m[2];
	temp.m[2] = -temp.m[1];
	temp.m[3] = temp.m[0];
	return (1 / determinate(D) * temp);*/
	/*return (1 / (determinate(D)) * transpose(D));*/
	return (1 / (determinate(D)) * mat2 { D.m[3], -D.m[1], -D.m[2], D.m[0] });
	//mat2 g = { D.m[3], -D.m[2], -D.m[1], D.m[0] };
	//return 1 / determinate(D) * g;
}
float determinate(const mat2 &D)
{
	return  (D.m[0] * D.m[3]) - (D.m[1] * D.m[2]);
}