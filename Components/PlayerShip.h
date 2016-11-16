#pragma once
#include "Transform.h"
#include "Collider.h"
#include "Rigidbody.h"
#include "SpaceshipController.h"
#include "spaceshipLocomotion.h"
#include "ShipRenderer.h"

class GameState;

class PlayerShip
{
public:
	Transform transform;
	Collider collider;
	Rigidbody rigidbody;
	SpaceshipController spaceshipcontroller;
	SpaceshipLocomotion spaceshiplocomotion;
	ShipRenderer shiprender;
	PlayerShip();
	

	void update(float deltaTime, class GameState &gs);
	void draw(const mat3 &camera);

};