#include "Collision.h"
#include <cmath>
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

	

	

	return retval;
}

SweptCollisionData1D sweptDtection1D(float Amin, float Amax, float Avel, float Bmin, float Bmax, float Bvel)
{
	SweptCollisionData1D retval;


	


	float HATZ = (Amin - Bmax) / (Bvel - Avel);
	float BOOTZ = (Bmin - Amax) / (Avel - Bvel);

	if (HATZ > BOOTZ)
	{
		retval.entryTime = BOOTZ;
		retval.ExitTime = HATZ;
	}
	else
	{
		retval.entryTime = HATZ;
		retval.ExitTime = BOOTZ;
	}
	retval.collisionNormal = copysignf(1, HATZ - BOOTZ);


	return retval;
}

CollisionData boxCollision(const AABB & A, const AABB & B)
{
	CollisionData retval;

	float NormalX = 0;
	float OTHERONE = 0;

	if (collisionDetection1D(A.min().x, A.max().x, B.min().x, B.max().x).penetrationDepth >
		collisionDetection1D(A.min().y, A.max().y, B.min().y, B.max().y).penetrationDepth)
	{
		retval.penetrationDepth = collisionDetection1D(A.min().y, A.max().y, B.min().y, B.max().y).penetrationDepth;
		OTHERONE = collisionDetection1D(A.min().y, A.max().y, B.min().y, B.max().y).collisionNormal;
	}
	else
	{
		retval.penetrationDepth = collisionDetection1D(A.min().x, A.max().x, B.min().x, B.max().x).penetrationDepth;
		NormalX = collisionDetection1D(A.min().x, A.max().x, B.min().x, B.max().x).collisionNormal;
	}


	retval.collisionNormal = { NormalX , OTHERONE };



	return retval;
}

float CollisionData1D::MTV() const
{
	return penetrationDepth * collisionNormal;
}

float CollisionData1D::result() const
{
	return penetrationDepth >= 0;
}

float CollisionData::MTV() const
{
	/*return penetrationDepth * collisionNormal;*/
	return 0;
}

vec2 CollisionData::result() const
{
	return vec2();
}
