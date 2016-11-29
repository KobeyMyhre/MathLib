#pragma once
#include "mat3.h"
#include "Transform.h"

class Track
{
public:
	bool m_lap = false;
	bool fungate = false;
	int laps = 0;
	float time;
	float GoTime;
	Transform Go;

	bool PickedUp = false;
	bool PickedUp2 = false;
	bool PickedUp3 = false;
	bool PickedUp4 = false;

	bool Effect = false;
	int Success = -1;

	void debugDrawGo(const mat3 &camera);

	//
	//
	// Duplicate function for each pick up... stupid fix
	//
	//
	//
	//
	//

};