#pragma once
#include "Transform.h"
#include "collider.h"
#include "Rigidbody.h"
class LapLine
{
public:
	Transform transform;
	Collider collider;
	Rigidbody rigidbody;

	LapLine();

	void update(float deltaTime, class GameState &gs);
	void draw(const mat3 &camera);



};