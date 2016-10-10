#pragma once
#include "Rigidbody.h"

class SpaceshipLocomotion
{

	
	float Vertthrust;
	float Horzthrust;
	float stopAction;
	
	
	float breakPower;
	float turn;
	float maxTurn;
	float turnspeed;

	float speed;
	float maxSpeed;
public:
	SpaceshipLocomotion();

	void doSTOP(float value);
	void doThrust(float value, float value1);
	void doTurn(float value);
	void update(const Transform &trans, Rigidbody &rigidbody);
};