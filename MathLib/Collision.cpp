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

CollisionDataSwept boxCollisionSwept(const AABB & A, const vec2 & dA, const AABB &B, const vec2 & dB)
{
	CollisionDataSwept retval;

	SweptCollisionData1D resX = sweptDtection1D(A.min().x, A.max().x, dA.x, B.min().x, B.max().x, dB.x);

	SweptCollisionData1D resY= sweptDtection1D(A.min().y, A.max().y, dA.y, B.min().y, B.max().y, dB.y);

	

	if (resY.entryTime < resX.entryTime && !isinf(resX.entryTime))
	{
		retval.collisionNormal = vec2{ 1,0 } *resX.collisionNormal;
		retval.entryTime = resX.entryTime;
	}
	else
	{
		retval.collisionNormal = vec2{ 0,1 } *resY.collisionNormal;
		retval.entryTime = resY.entryTime;
	}

	if (resY.ExitTime < resX.ExitTime || isinf(resX.ExitTime))
	{
		retval.exitTime = resY.ExitTime;
	}
	else
	{
		retval.exitTime = resX.ExitTime;
	}



	//float HATZ = (A.min().x - B.max().x) / (dB.x - dA.x);
	//float BOOTZ = (B.min().x - A.max().x) / (dA.x - dB.x);
	//float entryX;
	//float exitX;
	//float entryY;
	//float exitY;

	//entryX = fminf( HATZ, BOOTZ);
	//exitX = fmaxf( HATZ, BOOTZ);

	//retval.collisionNormal.x = copysignf(1, BOOTZ - HATZ);

	////Kobey kisses girls HA GAYYYYY :D - matt <3
	//

	//float SQUIRREL = (A.min().y - B.max().y) / (dB.y - dA.y);
	//float DINOSAUR = (B.min().y - A.max().y) / (dA.y - dB.y);

	//entryY = fminf(SQUIRREL, DINOSAUR);
	//exitY = fmaxf(SQUIRREL, DINOSAUR);



	//retval.collisionNormal.y = copysignf(1, DINOSAUR - SQUIRREL);

	//retval.entryTime = fmaxf(entryX, entryY);
	//retval.exitTime = fminf(exitX, exitY);


	
	return retval;
}

CollisionDataSwept SweptPlaneBoxCollision(const plane & P, const AABB & B, const vec2 & bA)
{
	CollisionDataSwept retval;

	vec2 TR = { B.max().x, B.max().y };
	vec2 TL = { B.min().x, B.max().y };
	vec2 BR = { B.max().x, B.min().y};
	vec2 BL ={ B.min().x, B.min().y };
	


	float PMAX = dot(P.dir, P.pos);

	
	float Bvel = dot(P.dir, bA);

	float FTR = dot(P.dir, TR);
	float FTL= dot(P.dir, TL);
	float FBR = dot(P.dir, BR);
	float FBL = dot(P.dir, BL);

	float AMin = fminf(fminf(FTR, FTL), fminf(FBR, FBL));
	float AMax = fmaxf(fmaxf(FTR, FTL), fmaxf(FBR, FBL));

	retval.entryTime = (AMin - PMAX) / (0 - Bvel);
	retval.exitTime = (AMax - PMAX) / (0 - Bvel);

	retval.collisionNormal = P.dir;
	//retval.collisionNormal = copysignf(1, retval.entryTime - retval.exitTime);

	return retval;
}

CollisionData PlaneBoxCollision(const plane & P, const AABB & B)
{
	CollisionData retval;

	vec2 TR = { B.max().x, B.max().y };
	vec2 TL = { B.min().x, B.max().y };
	vec2 BR = { B.max().x, B.min().y };
	vec2 BL = { B.min().x, B.min().y };

	float PMAX = dot(P.dir, P.pos);

	float FTR = dot(P.dir, TR);
	float FTL = dot(P.dir, TL);
	float FBR = dot(P.dir, BR);
	float FBL = dot(P.dir, BL);

	float AMin = fminf(fminf(FTR, FTL), fminf(FBR, FBL));
	float AMax = fmaxf(fmaxf(FTR, FTL), fmaxf(FBR, FBL));

	retval.penetrationDepth = PMAX - AMin;
	retval.collisionNormal = P.dir;

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

bool CollisionData::result() const
{
	return penetrationDepth >= 0;
}

bool CollisionDataSwept::result() const
{
	return false;
}
