#include "SpaceshipLocomotion.h"
#include "sfwdraw.h"
#include "Rigidbody.h"
SpaceshipLocomotion::SpaceshipLocomotion()
{
	Vertthrust = 0.f;
	Horzthrust = 0.f;
	maxThrust = 25.0f;

	turn = 0.f;
	maxTurn = 100.f;
	turnspeed = 1.f;

	speed = 500.f;
}


void SpaceshipLocomotion::doThrust(float value, float value1)
{
	Vertthrust = value;
	Horzthrust = value1;
	/*if (sfw::getKey('W')) Vertthrust = 5;
	if (sfw::getKey('S')) Vertthrust = -5;
	if (sfw::getKey('D'))Horzthrust = 5;
	if (sfw::getKey('A')) Horzthrust = -5;*/
}

void SpaceshipLocomotion::doTurn(float value)
{
	turn = value;
		/*if (sfw::getKey('Q')) turn += .5;
		if (sfw::getKey('E')) turn -= .5;*/
}

void SpaceshipLocomotion::update(Rigidbody & rigidbody, float deltaTime)
{
	
	rigidbody.acceleration.x = Horzthrust * speed;
	rigidbody.acceleration.y = Vertthrust * speed;
	rigidbody.angularVelocity += turn;
	
	if (magnitude(rigidbody.velocity) > maxThrust)
	{
		vec2 dir = normal(rigidbody.velocity);
		rigidbody.velocity = dir * maxThrust;
	}



	Horzthrust = 0.f;
	Vertthrust = 0.f;
	turn = 0.f;
}
