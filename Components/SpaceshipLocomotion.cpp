#include "SpaceshipLocomotion.h"
SpaceshipLocomotion::SpaceshipLocomotion()
{
	thrust = 0.f;
	maxThrust = 100.0f;
	thrustSpeed = 1.F;

	turn = 0.f;
	maxTurn = 100.f;
	turnspeed = 1.f;

	speed 10.f;
}
void SpaceshipLocomotion::doThrust(float deltaTime)
{
}

void SpaceshipLocomotion::doTurn(float deltaTime)
{
}

void SpaceshipLocomotion::integrate(Rigidbody & rigidbody)
{

}
