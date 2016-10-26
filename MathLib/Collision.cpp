#include "Collision.h"

CollisionData1D collisionDetection1D(float Amin, float Amax, float Bmin, float Bmax)
{
	CollisionData1D retval;

						// A4 A6  B5 B7 
						// A6 - B5 = 1     B7 - A4 = 3 
	float TEE = Amax - Bmin;
	float PEE= Bmax - Amin;
	float small;

	if (TEE > PEE)
	{
		small = PEE;
		retval.collisionNormal = -1;
	}
	else
	{
		small = TEE;
		retval.collisionNormal = 1;
	}

	retval.penetrationDepth = small;

	

	retval.result = retval.penetrationDepth >= 0;
	retval.MTV = retval.penetrationDepth * retval.collisionNormal;

	return retval;
}
