#pragma once
#include "Transform.h"
#include "collider.h"
#include "Rigidbody.h"
class ColliderObj
{
public:
	Transform transform;
	Collider collider;
	Rigidbody rigidbody;

	ColliderObj();

	void update(float deltaTime, class GameState &gs);
	void draw(const mat3 &camera);



};