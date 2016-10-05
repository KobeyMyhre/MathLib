#pragma once
#include "Rigidbody.h"

class SpaceshipLocomotion
{

	
	float Vertthrust;
	float Horzthrust;

	float maxThrust;
	

	float turn;
	float maxTurn;
	float turnspeed;

	float speed;
public:
	SpaceshipLocomotion();

	void doThrust(float value, float value1);
	void doTurn(float value);
	void update(Rigidbody &rigidbody, float deltaTime);
};