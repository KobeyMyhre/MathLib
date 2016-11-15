#include "Collider.h"
#include "shapeDraw.h"
#include "sfwdraw.h"
#include "ShipRenderer.h"
#include <cmath>
Collider::Collider(const vec2 * verts, int size) : Hull(verts,size)
{

	


	float minX = INFINITY;
	float minY = INFINITY;
	float maxX = -INFINITY;
	float maxY = -INFINITY;
	
	
	for (int i = 0; i < size; i++)
	{
		if (verts[i].x < minX)
		{
			minX = verts[i].x;
		}
		if (verts[i].y < minY)
		{
			minY = verts[i].y;
		}
		if (verts[i].x > maxX)
		{
			maxX = verts[i].x;
		}
		if (verts[i].y > maxY)
		{
			maxY = verts[i].y;
		}

		

	}
	vec2 min = { minX,minY };
	vec2 max = { maxX, maxY };
		box.pos = ( min + max ) / 2;
		box.he = (max - min) / 2;


}

void Collider::debugDraw(const mat3 & T, const Transform & trans)
{
	mat3 glob = T * trans.getGlobalTransform();
	//mat3 glob = T * trans.getGlobalTransform();
	//drawAABB((glob * AABB{ 0,0,6,6 }), WHITE);
	drawAABB(glob * box, 0x888888ff);
	drawHull(glob * Hull, 0x888888ff);
}

CollisionData ColliderCollision(const Transform &AT, const Collider  &AC, const Transform &BT, const Collider &BC)
{
	CollisionData retval;

	retval = boxCollision(AT.getGlobalTransform() * AC.box, BT.getGlobalTransform() * BC.box);

	if(retval.penetrationDepth >= 0)
		retval = hullCollision(AT.getGlobalTransform() * AC.Hull, BT.getGlobalTransform() * BC.Hull);

	return retval;


	
}

CollisionData StaticResolution(Transform & AT, Rigidbody & AR, const Collider & AC, const Transform & BT, const Collider & BC)
{
	CollisionData results = ColliderCollision(AT, AC, BT, BC);
	if (results.penetrationDepth >= 0)
	{

		vec2 MTV = results.penetrationDepth * results.collisionNormal;
		AT.m_position -= MTV;

		AR.velocity = reflect(AR.velocity, results.collisionNormal);

	}
	return results;
}

CollisionData DynamicResolution(Transform & AT, Rigidbody & AR, const Collider & AC, Transform & BT, Rigidbody & BR, const Collider & BC, float bounciness)
{
	CollisionData results = ColliderCollision(AT, AC, BT, BC);


	if (results.penetrationDepth >= 0)
	{
		vec2 MTV = results.penetrationDepth * results.collisionNormal;

		float am = magnitude(AR.mass * AR.velocity);
		float bm = magnitude(BR.mass * BR.velocity);
		float cm = am + bm;
		AT.m_position -= MTV * (1-am/cm);
		BT.m_position += MTV * (1 - bm / cm);


		vec2 a = AR.velocity;
		float p = AR.mass;
		vec2 x;

		vec2 b = BR.velocity;
		float q = BR.mass;
		vec2 y; 

		x = (a * p + b*q + -bounciness * (a - b)*q) / (q + p);
		y = bounciness * (a - b) + x;

		AR.velocity = -magnitude(x) * results.collisionNormal;
		BR.velocity = magnitude(y) * results.collisionNormal;

	}
	return results;
}
