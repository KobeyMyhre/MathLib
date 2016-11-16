#pragma once
#include "PlayerShip.h"
#include "Camera.h"
#include "ColliderObject.h"
#include "LapLine.h"
class GameState
{
public:
	PlayerShip player;
	Camera camera;
	LapLine lapline;
	static int laps;
	const static int BlocksNum = 47;
	ColliderObj blocks[BlocksNum];
	//player,init,term,step,draw
	int	d = -1;
	void play();
	void update(float deltaTime);
	void draw();
	void exit();
};