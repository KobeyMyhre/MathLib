#include <cassert>
#include <cstdio>
#include "Test.h"

int main()
{
	/*printf("Hello World! %d");*/
	// Unit Tests
	assert(doNothing(0) == 5);
	assert(doNothing(-1) == 4);
	assert(doNothing(1) == 8);

	assert(test_quad(0) == -7);
	assert(test_quad(-1) == -8);
	assert(test_quad(1) == -4);

	
	assert(quad(4, 1, -5).roots == 2);
	
	assert(lerp(0, 0, 0) == 0);
	
	assert(distance({ 0, 0 }, { 0,0 }) == 0);

	assert(inner({ 1, 1, 1 }, { 1, 1, 1 }) == 3);

	assert(Point({ 0, 0, 1, 1, }, { 0, 2, 0 }) == 1);

	/*getchar();*/
	return 0;
}