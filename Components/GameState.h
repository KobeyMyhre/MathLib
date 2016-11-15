#pragma once
#include "PlayerShip.h"
#include "Camera.h"
#include "ColliderObject.h"
class GameState
{
public:
	PlayerShip player;
	Camera camera;
	
	const static int BlocksNum = 3;
	ColliderObj blocks[BlocksNum];
	//player,init,term,step,draw

	void play();
	void update(float deltaTime);
	void draw();
};