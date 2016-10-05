#include "Rigidbody.h"
Rigidbody::Rigidbody()
{
	acceleration = vec2{ 0,0 };
	velocity = vec2{ 0,0 };
	angularVelocity = 0.0f;
	angularAcceletartion = 0.f;
}
void Rigidbody::addForce(const vec2 & force)
{
	acceleration += force;
}
void Rigidbody::addImpulse(const vec2 & impulse)
{
	velocity += impulse;
}
void Rigidbody::addTorque(float torque)
{
	angularAcceletartion += torque;
}
void Rigidbody::integrate(Transform & trans, float deltaTime)
{
	velocity += acceleration * deltaTime;

	trans.position = trans.position + velocity * deltaTime;
	trans.facing = trans.facing + angularVelocity * deltaTime;
}
