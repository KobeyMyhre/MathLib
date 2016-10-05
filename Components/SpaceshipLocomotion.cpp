#include "SpaceshipLocomotion.h"
#include "sfwdraw.h"
#include "Rigidbody.h"
SpaceshipLocomotion::SpaceshipLocomotion()
{
	Vertthrust = 0.f;
	Horzthrust = 0.f;

	turnspeed = 4.f;
	speed = 100.f;
	maxSpeed = 250.0f;
}


void SpaceshipLocomotion::doSTOP(float value)
{
	stopAction += value;
}

void SpaceshipLocomotion::doThrust(float value, float value1)
{
	Vertthrust = value;
	Horzthrust = value1;
	
}

void SpaceshipLocomotion::doTurn(float value)
{
	turn = value;
		
}

void SpaceshipLocomotion::update(const Transform &trans, Rigidbody & rigidbody)
{
	rigidbody.addForce(trans.getDirection() * speed * Vertthrust);
	rigidbody.addTorque(turnspeed * Horzthrust);

	float currentSpeed = magnitude(rigidbody.velocity);
	rigidbody.addForce(-rigidbody.velocity);
	rigidbody.addTorque(-rigidbody.angularVelocity);
	
	Horzthrust = 0;
	Vertthrust = 0;
	
}
