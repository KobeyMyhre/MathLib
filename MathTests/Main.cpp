#include <cassert>
#include <iostream>
#include "Test.h"
#include "vec2.h"
#include "vec3.h"
#include "flops.h"
#include <cmath>
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

	return 0;

}