#include "Rigidbody.h"
#include "sfwdraw.h"
Rigidbody::Rigidbody()
{
	drag = .25;
	angularDrag = .3;
	mass = 1;
	force = vec2 { 0,0 };
	impulse = vec2 { 0,0 };
	torque = 0;
	acceleration = vec2{ 0,0 };
	velocity = vec2{ 0,0 };

	angularVelocity = 0.0f;
	angularAcceletartion = 0.f;
}
void Rigidbody::addForce(const vec2 & a_force)
{
	force += a_force;
}
void Rigidbody::addImpulse(const vec2 & a_impulse)
{
	velocity += a_impulse;
}
void Rigidbody::addTorque(float a_torque)
{
	torque += a_torque;
}
void Rigidbody::integrate(Transform & trans, float deltaTime)
{
	acceleration	 = force / mass;
	velocity		+= acceleration * deltaTime + impulse / mass;
	trans.m_position	+= velocity * deltaTime;
	force = impulse	= { 0,0 };

	force = -velocity*drag;
	

	angularAcceletartion = torque / mass;
	angularVelocity		+= angularAcceletartion * deltaTime;
	trans.m_facing		+= angularVelocity * deltaTime;
	torque = 0;
	torque = -angularDrag * angularDrag;
}

void Rigidbody::debugDraw(const Transform & trans)
{
	vec2 p = trans.m_position ;
	vec2 v = p - -(velocity);
	vec2 a = acceleration + p;
	sfw::drawLine(p.x, p.y, v.x, v.y, BLACK);
	sfw::drawCircle(v.x, v.y , 7, 3, RED);
	/*sfw::drawCircle(v.x , v.y - 3 , 2, RED);*/
	/*sfw::drawLine(p.x, p.y, v.x, v.y, YELLOW);*/
}
