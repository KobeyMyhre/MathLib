#include "SpaceshipController.h"
#include "sfwdraw.h"

SpaceshipController::SpaceshipController(int up, int down, int left, int right, int stop)
{
	keyup = up;
	keydown = down;
	keyLeft = left;
	keyright = right;
	keystop = stop;

}

void SpaceshipController::update(SpaceshipLocomotion & loco)
{
	float vInput = 0.f;
	vInput -= sfw::getKey(keyright);
	vInput += sfw::getKey(keyLeft);
	
	float hInput = 0.f;
	hInput -= sfw::getKey(keyup);
	hInput += sfw::getKey(keydown);
	
	float bInput = sfw::getKey(keystop);

	loco.doThrust(hInput, vInput);
	loco.doSTOP(bInput);
}
