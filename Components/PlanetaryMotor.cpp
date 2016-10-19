#include "PlanetaryMotor.h"

void PlanetaryMotor::update(Rigidbody & planetRbody)
{
	
	planetRbody.addTorque(m_roatationSpeed);
	if (m_roatationSpeed >= m_maxroatSpeed)
	{
		m_roatationSpeed = m_maxroatSpeed;
	}
	
}
