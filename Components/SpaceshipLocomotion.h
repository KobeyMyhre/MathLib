#pragma once
#include "Rigidbody.h"

class SpaceshipLocomotion
{
public:
	
	float Vertthrust;
	float Horzthrust;
	float stopAction;
	
	
	float breakPower;
	float turn;
	float maxTurn;
	float turnspeed;

	
	float maxSpeed;

	SpaceshipLocomotion();
	float speed;
	void doSTOP(float value);
	void doThrust(float value, float value1);
	void doTurn(float value);
	void update(const Transform &trans, Rigidbody &rigidbody);
	

};