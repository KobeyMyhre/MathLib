#pragma once
#include "Transform.h"
#include "collider.h"
#include "Rigidbody.h"
class WhirlPool
{
public:
	Transform transform;
	Collider collider;
	Rigidbody rigidbody;

	WhirlPool();


	void update(float deltaTime, class GameState &gs);
	void draw(const mat3 &camera);



};