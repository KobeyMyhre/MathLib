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
	LapLine lapline[2];
	Track track;
	static int laps;
	const static int BlocksNum = 47;
	ColliderObj blocks[BlocksNum];
	static float time;
	//player,init,term,step,draw
	int	d = -1;
	void play();
	void update(float deltaTime);
	void draw();
	void exit();
};