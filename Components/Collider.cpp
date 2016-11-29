#include "Collider.h"
#include "shapeDraw.h"
#include "sfwdraw.h"
#include "ShipRenderer.h"
#include <cmath>
#include "Laps.h"
#include "GameState.h"
#include "LapLine.h"
#include <iostream>
#include "PickUps.h"
Collider::Collider()
{
}
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

void Collider::debugDrawHull(const mat3 & T, const Transform & trans,unsigned color)
{
	mat3 glob = T * trans.getGlobalTransform();
	drawHull(glob * Hull, color);
}

CollisionData ColliderCollision(const Transform &AT, const Collider  &AC, const Transform &BT, const Collider &BC)
{
	CollisionData retval;

	retval = boxCollision(AT.getGlobalTransform() * AC.box, BT.getGlobalTransform() * BC.box);

	if(retval.penetrationDepth >= 0)
		retval = hullCollision(AT.getGlobalTransform() * AC.Hull, BT.getGlobalTransform() * BC.Hull);

	return retval;


	
}

CollisionData StaticResolution( Transform & AT, Rigidbody & AR, const Collider & AC, const Transform & BT, const Collider & BC, float bounciness)
{
	CollisionData results = ColliderCollision(AT, AC, BT, BC);
	if (results.penetrationDepth >= 0)
	{

		vec2 MTV = results.penetrationDepth * results.collisionNormal;
		AT.m_position -= MTV;

		AR.velocity = reflect(AR.velocity, results.collisionNormal) * bounciness;

	}
	return results;
}
CollisionData StaticResolutionForPickUps(Track &T, Transform & AT, SpaceshipLocomotion &AS, const Collider & AC,  Transform & BT, const Collider & BC, float bounciness)
{
	CollisionData results = ColliderCollision(AT, AC, BT, BC);
	if (results.penetrationDepth >= 0 && T.PickedUp == false)
	{
		AS.speed += 100;
		T.PickedUp = true;
	}
	return results;
}
CollisionData StaticResolutionForPickUps2(Track &T, Transform & AT, SpaceshipLocomotion &AS, const Collider & AC, Transform & BT, const Collider & BC, float bounciness)
{
	CollisionData results = ColliderCollision(AT, AC, BT, BC);
	if (results.penetrationDepth >= 0 && T.PickedUp2 == false)
	{
		AS.speed += 100;
		T.PickedUp2 = true;
	}
	return results;
}
CollisionData StaticResolutionForPickUps3(Track &T, Transform & AT, SpaceshipLocomotion &AS, const Collider & AC, Transform & BT, const Collider & BC, float bounciness)
{
	CollisionData results = ColliderCollision(AT, AC, BT, BC);
	if (results.penetrationDepth >= 0 && T.PickedUp3 == false)
	{
		AS.speed += 100;
		T.PickedUp3 = true;
	}
	return results;
}
CollisionData StaticResolutionForPickUps4(Track &T, Transform & AT, SpaceshipLocomotion &AS, const Collider & AC, Transform & BT, const Collider & BC, float bounciness)
{
	CollisionData results = ColliderCollision(AT, AC, BT, BC);
	if (results.penetrationDepth >= 0 && T.PickedUp4 == false)
	{
		AS.speed += 100;
		T.PickedUp4 = true;
	}
	return results;
}
CollisionData StaticResolutionBoosts(Transform & AT, Rigidbody & AR, const Collider & AC, const Transform & BT, const Collider & BC, float bounciness)
{
	CollisionData results = ColliderCollision(AT, AC, BT, BC);
	if (results.penetrationDepth >= 0)
	{
	/*vec2 dir = normal(BT.getGlobalPosition() -
			AT.getGlobalPosition());
		AR.addImpulse(dir * 50);*/

		AR.addImpulse(vec2{ 100,0 });


	}



	return results;
}
CollisionData StaticResolutionWithEffect(Track &T,Transform & AT, Rigidbody & AR, const Collider & AC, const Transform & BT, const Collider & BC, float bounciness)
{
	


	CollisionData results = ColliderCollision(AT, AC, BT, BC);
	if (results.penetrationDepth >= 0)
	{
		
		vec2 MTV = results.penetrationDepth * results.collisionNormal;
		AT.m_position -= MTV;
		AR.velocity = reflect(AR.velocity, results.collisionNormal) * bounciness;
		T.Effect = true;


	}
	

	
	return results;
}
CollisionData LapResolution(Track &T, Transform & AT, Rigidbody & AR, const Collider & AC, const Transform & BT, const Collider & BC, const Transform & BTX, const Collider & BCX)
{
	
	
	
	// have second lapline
	// check if lapline collision one passed, bool = true
	// check if 2nd lapline collision passed , bool = truew, laps ++, bools set =false
	CollisionData results = ColliderCollision(AT, AC, BTX, BCX);
	
	
	if (results.penetrationDepth >= 0)
	{
		T.m_lap = true;
		
		
		
	}
	
	CollisionData results1 = ColliderCollision(AT, AC, BT, BC);
	if (results1.penetrationDepth >= 0 && T.m_lap == true)
	{
		
			
			if(T.m_lap == true )
			{
				if (T.laps == 0)
					T.time += 20.f;
				if (T.laps == 1)
					T.time += 17.f;
				if (T.laps == 2)
					T.time += 14.f;
				if (T.laps == 3)
					T.time += 11.f;

				T.laps++;
				
				T.m_lap = false;
				T.PickedUp = false;
				T.PickedUp2 = false;
				T.PickedUp3 = false;
				T.PickedUp4 = false;
			}

		
		

	}
	
	return results,results1;
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

CollisionData FunGateResolution(Track & T, Transform & AT, SpaceshipLocomotion & AR, const Collider & AC, const Transform & BT, const Collider & BC, const Transform & BTX, const Collider & BCX)
{
	CollisionData results = ColliderCollision(AT, AC, BTX, BCX);


	if (results.penetrationDepth >= 0)
	{
		T.fungate = true;



	}

	CollisionData results1 = ColliderCollision(AT, AC, BT, BC);
	if (results1.penetrationDepth >= 0 && T.fungate == true)
	{


		if (T.fungate == true)
		{
			T.time = INFINITY;
			AR.speed = 1800.f;
			
			
			T.fungate = false;
		
		}




	}

	return results, results1;
}
