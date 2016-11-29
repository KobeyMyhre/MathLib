#pragma once
#include "shapes.h"
#include "Transform.h"
#include "collision.h"
#include "Rigidbody.h"
#include "TrackManager.h"
#include "SpaceshipLocomotion.h"

class Collider
{
public:
	AABB box;
	hull Hull;
	
	Collider();
	Collider(const vec2 *verts, int size);
	
	void debugDraw(const mat3 &T, const Transform &trans);
	void debugDrawHull(const mat3 &T, const Transform &trans,unsigned color);
};

CollisionData ColliderCollision(const Transform &AT, const Collider &AC, const Transform &BT, const Collider &BC);

CollisionData StaticResolution( Transform &AT, Rigidbody &AR, const Collider &AC, const Transform &BT, const Collider &BC, float bounciness);
CollisionData StaticResolutionForPickUps(Track &T,Transform &AT,SpaceshipLocomotion &AS, const Collider &AC,  Transform &BT, const Collider &BC, float bounciness);
CollisionData StaticResolutionForPickUps2(Track &T, Transform &AT, SpaceshipLocomotion &AS, const Collider &AC, Transform &BT, const Collider &BC, float bounciness);
CollisionData StaticResolutionForPickUps3(Track &T, Transform &AT, SpaceshipLocomotion &AS, const Collider &AC, Transform &BT, const Collider &BC, float bounciness);
CollisionData StaticResolutionForPickUps4(Track &T, Transform &AT, SpaceshipLocomotion &AS, const Collider &AC, Transform &BT, const Collider &BC, float bounciness);
CollisionData StaticResolutionBoosts(Transform &AT, Rigidbody &AR, const Collider &AC, const Transform &BT, const Collider &BC, float bounciness);

CollisionData StaticResolutionWithEffect(Track &T,Transform & AT, Rigidbody & AR, const Collider & AC, const Transform & BT, const Collider & BC, float bounciness);
CollisionData LapResolution(Track &T,Transform & AT, Rigidbody & AR, const Collider & AC, const Transform & BT, const Collider & BC, const Transform & BTX, const Collider & BCX);
CollisionData DynamicResolution(Transform &AT, Rigidbody &AR, const Collider &AC,  Transform &BT, Rigidbody &BR, const Collider &BC, float bounciness = 1);
CollisionData FunGateResolution(Track &T, Transform & AT, SpaceshipLocomotion & AR, const Collider & AC, const Transform & BT, const Collider & BC, const Transform & BTX, const Collider & BCX);
CollisionData WhirlPoolResolution(Track &T, Transform &AT, SpaceshipLocomotion &AR, const Collider &AC, const Transform &BT, const Collider &BC, float bounciness);