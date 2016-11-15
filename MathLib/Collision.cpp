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

CollisionData hullCollision(const hull &A, const hull &B)
{
	CollisionData retval;

	retval.penetrationDepth = INFINITY;

	A.vertices[A.size];
	B.vertices[B.size];
	float aPD;
	float aCN;
	float aPerpVertA[16];
	float aPerpVertB[16];
	


	float aPlaceholder1;
	float aPlaceholder2;

	float bPlaceholder1;
	float bPlaceholder2;

	
	float bPD;
	float bCN;

	float bPerpVertA[16];
	float bPerpVertB[16];



	for (int j = 0; j < A.size; j++)
	{
		float aAmini = INFINITY;
		float aBmini = INFINITY;
		float aAmaxi = -INFINITY;
		float aBmaxi = -INFINITY;

		for (int i = 0; i < A.size; i++)
		{
			aPerpVertA[i] = dot(A.vertices[i], A.normals[j]);
			aAmini = fminf(aAmini, aPerpVertA[i]);
			aAmaxi = fmaxf(aAmaxi, aPerpVertA[i]);
		}
		for (int i = 0; i < B.size; i++)
		{
			aPerpVertB[i] = dot(B.vertices[i], A.normals[j]);
			aBmini = fminf(aBmini, aPerpVertB[i]);
			aBmaxi = fmaxf(aBmaxi, aPerpVertB[i]);
		}
	

		
			aPlaceholder1 = aAmaxi - aBmini;	//R
			aPlaceholder2 = aBmaxi - aAmini;	//L
			aPD = fminf(aPlaceholder1, aPlaceholder2);
			aCN = copysignf(1, aPlaceholder2 - aPlaceholder1);

		

		if (aPD < retval.penetrationDepth)
		{
			retval.penetrationDepth = aPD;
			retval.collisionNormal = aCN * A.normals[j];
		}

	}
	for (int j = 0; j < B.size; j++)
	{
		float bAmini = INFINITY;
		float bBmini = INFINITY;
		float bAmaxi = -INFINITY;
		float bBmaxi = -INFINITY;

		for (int i = 0; i < A.size; i++)
		{
			bPerpVertA[i] = dot(A.vertices[i], B.normals[j]);
			bAmini = fminf(bAmini, bPerpVertA[i]);
			bAmaxi = fmaxf(bAmaxi, bPerpVertA[i]);
		}
		for (int i = 0; i < B.size; i++)
		{
			bPerpVertB[i] = dot(B.vertices[i], B.normals[j]);
			bBmini = fminf(bBmini, bPerpVertB[i]);
			bBmaxi = fmaxf(bBmaxi, bPerpVertB[i]);
		}
		
		bPlaceholder1 = bAmaxi - bBmini;
		bPlaceholder2 = bBmaxi - bAmini;
		bPD = fminf(bPlaceholder1, bPlaceholder2);
		bCN = copysignf(1, bPlaceholder2 - bPlaceholder1);
			
		
		if (bPD < retval.penetrationDepth)
		{
			retval.penetrationDepth = bPD;
			retval.collisionNormal = bCN * B.normals[j];
		}
	}
	return retval;
}



//CollisionDataSwept SweptHullCollision(const hull & A, const hull & B, const vec2 & dA, const vec2 & dB)
//{
//	CollisionDataSwept retval;
//
//	/*retval.penetrationDepth = INFINITY;*/
//
//
//	
//
//	
//
//	A.vertices[A.size];
//	B.vertices[B.size];
//	
//
//	float bAmini = INFINITY;
//	float bBmini = INFINITY;
//	float bAmaxi = -INFINITY;
//	float bBmaxi = -INFINITY;
//	float aAmini = INFINITY;
//	float aBmini = INFINITY;
//	float aAmaxi = -INFINITY;
//	float aBmaxi = -INFINITY;
//	
//
//
//		//if (magnitude(dA) == 0 && magnitude(dB) == 0)
//		//{
//		//	hullCollision(A, B);
//
//
//		//}
//		// for each axis
//			// Find the min, max, and velocity projected along that axis for each object
//
//			// if (aVel - bVel == 0)
//				// find penetration depth instead
//
//			// if depth < 0 : return infinity for entry time
//
//		{
//			float aVel = dot(A.normals[A.size], dA);
//			float bVel = dot(B.normals[B.size], dB);
//
//			float HATZ = (aAmini - aBmaxi) / (bVel - aVel);
//			float BOOTZ = (aBmini - aAmaxi) / (aVel - bVel);
//			if (HATZ > BOOTZ)
//			{
//				retval.entryTime = BOOTZ;
//				retval.exitTime = HATZ;
//			}
//			else
//			{
//				retval.entryTime = HATZ;
//				retval.exitTime = BOOTZ;
//			}
//			retval.collisionNormal = A.normals[A.size];
//		}
//		
//		
//	
//	}
//	return retval;
//}

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
CollisionData HullCollisionGroup(const hull A[], unsigned asize,
	const hull B[], unsigned bsize)
{
	CollisionData retval;

	retval.penetrationDepth = INFINITY;
	for (int i = 0; i < asize; ++i)
		for (int j = 0; j < bsize; ++j)
		{
			CollisionData temp = hullCollision(A[i], B[j]);
			if (temp.penetrationDepth < retval.penetrationDepth);
			retval = temp;

		}
	return retval;
}
	
