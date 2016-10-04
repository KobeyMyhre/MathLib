
#pragma once
#include "vec2.h"
#include "Transform.h"

class Rigidbody
{
public:
	Rigidbody();
	vec2 velocity;

	float angularVelocity;
	float angularAcceletartion;

	vec2 acceleration;

	void integrate(Transform &trans, float deltaTime);

};