#pragma once
#include "Transform.h"
#include "collider.h"
#include "Rigidbody.h"
#include "TrackManager.h"
class PickUps
{
public:
	Transform transform;
	Collider collider;
	Rigidbody rigidbody;
	
	

	PickUps();

	void update(float deltaTime, class GameState &gs);
	void draw(const mat3 &camera, Track &track);
	void draw2(const mat3 &camera, Track &track);
	void draw3(const mat3 &camera, Track &track);
	void draw4(const mat3 &camera, Track &track);



};