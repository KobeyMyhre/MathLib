// this is develop branch
#include "Test.h"
#include <cmath>
int doNothing(int x)
{
	return x*x + 2 * x + 5;
}

float test_quad(float x)
{
	return x*x + 2*x - 7;
}

quad_results quad(float a, float b, float c)
{
	quad_results retval;
	
	retval.left_root = (b*-1 + sqrt(b * b - 4 * a*c) / (2 * a));
	retval.right_root = (b*-1 - sqrt(b * b - 4 * a*c) / (2 * a));
	
	float discr = b*b - 4 * a*c;

	if (discr < 0)
	{
		retval.roots = 0;
	}
	else if (discr == 0.0f)
	{
		retval.roots = 1;
	}
	else
	{
		retval.roots = 2;
	}
	
	return retval;
}

//float lerp(float start, float end, float t)
//{
//	
//	return start + t*(end - start);
//}

float distance(oint p1, oint p2)
{
	return (sqrt((p2.x - p1.x)*(p2.x - p1.x) + (p2.x - p1.y)*(p2.y - p1.y)));
}

float inner(hoint p1, hoint q2)
{
	return ((p1.x*q2.x) + (p1.y*q2.y) + (p1.z*q2.z));
}


float Point(Plane plane, Xoint point)
{
	return ((plane.a * point.x) + (plane.b * point.y) + (plane.c * point.z) + plane.d) / sqrt((plane.a*plane.a) + (plane.b * plane.b) + (plane.c*plane.c));
}

//float distance(float x1, float y1, float x2, float y2)
//{
//	return 
//}

