#pragma once
#include "PlayerShip.h"
#include "Camera.h"
#include "ColliderObject.h"
#include "LapLine.h"
#include "PickUps.h"
#include "MenuState.h"
#include "SpeedBoost.h"
class GameState
{
public:
	PlayerShip player;
	Camera camera;
	LapLine lapline[4];
	Track track;
	PickUps pickups[4];
	SpeedBoost speedboost[2];

	static int laps;
	const static int BlocksNum = 46;
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