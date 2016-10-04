#include "Rigidbody.h"
Rigidbody::Rigidbody()
{
	acceleration = vec2{ 0,0 };
	velocity = vec2{ 0,0 };
	angularVelocity = 0.0f;
	angularAcceletartion = 0.f;
}
void Rigidbody::integrate(Transform & trans, float deltaTime)
{
	velocity += acceleration * deltaTime;

	trans.position = trans.position + velocity * deltaTime;
	trans.facing = trans.facing + angularVelocity * deltaTime;
}
