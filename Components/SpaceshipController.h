#pragma once
#include "SpaceshipLocomotion.h"

//class SpaceShipController
//{
//public:
//	unsigned CTR_LEFT, CTR_RIGHT, CTR_FORWARD, CTR_BACKWARDS, CTR_BREAK;
//	SpaceShipController(unsigned CTR_LEFT = 'A', unsigned CTR_RIGHT = 'D', unsigned CTR_FORWARD = 'W', unsigned CTR_BACKWARDS = 'D', unsigned CTR_BREAK = ' ');
//	
//	void update(SpaceshipLocomotion &loco);
//};


class SpaceshipController
{
public:
	unsigned keyup, keydown, keyLeft, keyright, keystop;
	//'W', 'S', 'A', 'D', ' '
	SpaceshipController(int keyup = 'W', int Keydown = 'S', int Keyleft = 'A', int Keyright = 'D', int stop = ' ');



	void update(SpaceshipLocomotion &loco);
};
