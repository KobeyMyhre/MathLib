#include "SpaceshipController.h"
#include "sfwdraw.h"
void SpaceShipController::update(SpaceshipLocomotion & loco)
{
	float vInput = 0.f;
	vInput -= sfw::getKey('A');
	vInput += sfw::getKey('D');
	
	float hInput = 0.f;
	hInput -= sfw::getKey('S');
	hInput += sfw::getKey('W');
	
	loco.doThrust(hInput, vInput);

}
