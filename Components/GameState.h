#pragma once
#include "PlayerShip.h"
#include "Camera.h"
#include "ColliderObject.h"
#include "LapLine.h"
#include "PickUps.h"
#include "MenuState.h"
class GameState
{
public:
	PlayerShip player;
	Camera camera;
	LapLine lapline[2];
	Track track;
	PickUps pickups[4];
	static int laps;
	const static int BlocksNum = 44;
	ColliderObj blocks[BlocksNum];
	static float time;
	//player,init,term,step,draw
	int	d = -1;
	int w;

	bool GameOver;
	bool movement;
	bool Red ;
	bool Yellow ;
	bool Green ;
	
	

	void play();
	void update(float deltaTime);
	void draw();
	MenuState GameState::nextAppState();
	bool isGameOver() { return GameOver; }
	void exit();
};