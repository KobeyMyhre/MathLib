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

	/*getchar();*/
	return 0;
}