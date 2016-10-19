#pragma once
#include "Rigidbody.h"
class PlanetaryMotor
{
public:
	float m_roatationSpeed;
	float m_maxroatSpeed;
	void update(Rigidbody &planetRbody);
};






