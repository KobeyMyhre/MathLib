#pragma once
#include "vec2.h"
#include "shapes.h"
struct CollisionData1D
{
	
	float penetrationDepth; // how much overlap
	float collisionNormal; // -1 or 1
	float MTV() const;
	float result() const;


};
struct SweptCollisionData1D
{
	float entryTime, ExitTime;
	float collisionNormal;

	bool result() const;
};

CollisionData1D collisionDetection1D(float Amin, float Amax, float Bmin, float Bmax);

SweptCollisionData1D sweptDtection1D(float Amin, float Amax, float Avel, float Bmin, float Bmax, float Bvel);


struct CollisionData
{
	float penetrationDepth; // how much overlap
	vec2 collisionNormal; // -1 or 1
	
	
	float MTV() const;
	bool result() const;
};

CollisionData boxCollision(const AABB &A,
						    const AABB &B);

struct CollisionDataSwept
{
	float entryTime, exitTime;
	vec2 collisionNormal;

	bool result() const;
};

CollisionDataSwept boxCollisionSwept(const AABB &A, const vec2 &dA, const AABB &B ,const vec2 &dB);
bool operator==(const AABB &A, const AABB &B);

CollisionData PlaneBoxCollision(const plane &P, const AABB &B);

CollisionDataSwept SweptPlaneBoxCollision(const plane & P, const AABB & B, const vec2 & bA);

CollisionData hullCollision(const hull &A, const hull &B);






