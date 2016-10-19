
#pragma once
#include "vec2.h"
#include "Transform.h"

class Rigidbody
{
public:
	Rigidbody();
	float mass, drag, angularDrag;
	
	vec2 force, impulse;
	vec2 velocity;

	float torque;
	float angularVelocity;
	float angularAcceletartion;
	
	void addForce(const vec2 &a_force);
	void addImpulse(const vec2 &a_impulse);
	
	void addTorque(float a_torque);
	
	vec2 acceleration;

	void integrate(Transform &trans, float deltaTime);
	void debugDraw(const Transform &trans, const mat3 &T = mat3Identity());
};