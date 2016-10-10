#include "SpaceshipController.h"
#include "sfwdraw.h"

SpaceShipController::SpaceShipController(unsigned a_CTR_LEFT, unsigned a_CTR_RIGHT, unsigned a_CTR_FORWARD, unsigned a_CTR_BACKWARDS, unsigned a_CTR_BREAK)
{
	CTR_LEFT = a_CTR_LEFT;
	CTR_RIGHT = a_CTR_RIGHT;
	CTR_FORWARD= a_CTR_FORWARD;
	CTR_BACKWARDS = a_CTR_BACKWARDS;
	CTR_BREAK = a_CTR_BREAK;
}

void SpaceShipController::update(SpaceshipLocomotion & loco)
{
	float vInput = 0.f;
	vInput -= sfw::getKey('D');
	vInput += sfw::getKey('A');
	
	float hInput = 0.f;
	hInput -= sfw::getKey('S');
	hInput += sfw::getKey('W');
	
	float bInput = sfw::getKey(' ');

	loco.doThrust(hInput, vInput);
	loco.doSTOP(bInput);
}
