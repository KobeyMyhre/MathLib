#include <cassert>
#include <iostream>
#include "Test.h"
#include "vec2.h"
#include "vec3.h"
#include "flops.h"
#include <cmath>
#include "mat2.h"
#include "mat3.h"

int main()
{
	/*assert(donothing(0) == 5);
	assert(donothing(-1) == 4);
	assert(donothing(1) == 8);

	assert(test_quad(0) == -7);
	assert(test_quad(-1) == -8);
	assert(test_quad(1) == -4);


	assert(quad(4, 1, -5).roots == 2);

	assert(lerp(0, 0, 0) == 0);

	assert(distance({ 0, 0 }, { 0,0 }) == 0);

	assert(INNER({ 0, 0, 0, }, { 0, 0, 0 }) == 0);

	assert(Point({ 0, 0, 1, 1, }, { 0, 2, 0 }) == 1);*/

	////////////////////VECTOR TESTS//////////////////

	assert((vec2{ 0,0 } == vec2{ 0,0 }));

	assert((vec2{ 1,1 } +vec2{ -1,0 } == vec2{ 0,1 }));
	assert((vec2{ 1,1 } -vec2{ 0,0 } == vec2{ 1,1 }));
	assert((vec2{ 1,1 } *vec2{ 0,0 } == vec2{ 0,0 }));
	assert((vec2{ 1,1 } / vec2{ 1,1 } == vec2{ 1,1 }));

	assert(((vec2{ 1,1 } *1.f) == vec2{ 1, 1 }));
	assert(((1.f * vec2{ 1,1 }) == vec2{ 1, 1 }));
	assert(((vec2{ 1,1 } / 1.f) == vec2{ 1, 1 }));
	/*assert(((1.f / vec2{ 1,1 }) == vec2{ 1, 1 }));*/


	assert((-(vec2{ 1 ,1 }) == vec2{ -1, -1 }));
	assert((vec2{ 0,0 } == vec2{ 0,0 } -vec2{ 0, 0 }));
	assert((vec2{ 0,0 } == vec2{ 0,0 } +vec2{ 0, 0 }));
	assert((vec2{ 0,0 } == vec2{ 0,0 } *vec2{ 0, 0 }));
	assert((vec2{ 1,1 } == vec2{ 1,1 } / vec2{ 1, 1 }));

	assert((vec2{ 1,1 } == vec2{ 1,1 }));
	assert((vec2{ 1,1 } != vec2{ 2,2 }));



	assert(fequals(magnitude(vec2{ 4,0 }), 4));
	assert(fequals(magnitude(vec2{ -4,0 }), 4));

	//assert(fequals(normal(vec2{ 4,0 }), 4));

	assert(fequals(dot(vec2{ 5,4 }, vec2{ 1,0 }), 5));
	assert(fequals(angleBetween(vec2{ 0,1 }, vec2{ 1,0 }), deg2rad(90)));
	//assert(perp)
	assert((fromAngle(0) == vec2{ 1,0 }));
	assert((cross(vec3{ 1, 0, 0 }, vec3{ 0, 1, 0 }) == vec3{ 0,0,1 }));


	assert(fequals(1, .9999999f));
	assert(fequals(lerp(.23, 124, 0), .23));
	assert(fequals(lerp(0, 1, .5f), .5f));

	assert(fequals(quadBezier(15, 40, 21, 0), 15));
	assert(fequals(quadBezier(15, 40, 21, 1), 21));

	assert(fequals(hermitspline(15, 40, 21, 10, 0), 15));
	assert(fequals(hermitspline(15, 40, 21, 10, 1), 21));

	assert(fequals(cardinalSpline(15, 40, 21, .2f, 0), 15));
	assert(fequals(cardinalSpline(15, 40, 21, .1f, 1), 21));

	assert(fequals(catRomSpline(15, 40, 21, 0), 15));
	assert(fequals(catRomSpline(15, 40, 21, 1), 21));

	assert(fequals(1, .9999999f));

	/////////////////////////////////////

	mat2 m0 = mat2{ 0,0,0,0 };
	mat2 mI = mat2Identity();
	mat2 t0 = mat2{ 4,3,2,1 };
	vec2 v0 = vec2{ 1,0 };

	assert(m0 == m0);
	assert(mI * 2 == 2 * mI);

	assert(mI * v0 == v0);

	assert(transpose(mI) == mI);

	//assert(inverse(mI) == mI);
	assert(t0*inverse(t0) == mI);

	mat3 m1 = { 1,2,3,4,5,6,7,0,9 };
	mat3 m2 = mat3Identity();

	assert(m2 *inverse(m2) == m2);

	vec3 j = { 2,5,1 };
	vec3 s = scale(5, 1) * j;
	assert((scale(5, 1) * j == vec3{ 10,5,1 }));

	assert((rotation(deg2rad(90)) * j == vec3{ -5,2,1 }));

	assert((translate(0, 3)*j == vec3{ 2,8,1 }));

	/*assert((translate(4, 3) * j)* (scale(2, 1) * j)* (rotation(deg2rad(90) * j)) == mat3{0, 2, 4,
																			-1, 0, 3, 0, 0, 1})*/


	assert((rotation(deg2rad(-90)) * translate(10, 0) * rotation(deg2rad(45)) *  translate(4, 0) *  rotation(deg2rad(45)) * translate(6, 4) *  translate(-6, 0) * vec3 { 0, 0, 1 } == vec3{ 2 * sqrtf(2), -6 -2 * sqrtf(2), 1 }));


	return 0;

}