#include "GameState.h"
#include "objectCollision.h"
#include "sfwdraw.h"
#include "Laps.h"
#include "LapLine.h"
#include <stdlib.h>

int GameState::laps = 0;



void GameState::play()
{
	if (d == -1)
	{
		d = sfw::loadTextureMap("./res/fontmap.png", 16, 16);
	}
	GameOver = false;
	track.laps = 0;
	track.time = 34.f;
	track.GoTime = 6.f;
	
	
	player.spaceshiplocomotion.speed = 850.f;
	player.transform.m_position = vec2{ 250,200 };
	player.transform.m_facing = -1.57;
	
	track.PickedUp = false;
	track.PickedUp2 = false;
	track.PickedUp3 = false;
	track.PickedUp4 = false;
	
	movement = false;
	
	Red = false;
	Yellow = true;
	Green = true;

	track.Go.m_position = vec2{ 250, 600 };
	track.Go.m_color = RED;

	lapline[0].transform.m_position = vec2{ 600,0 };
	lapline[1].transform.m_position = vec2{ 1000,0 };
	pickups[0].transform.m_position = vec2{ -200,2150 };
	pickups[1].transform.m_position = vec2{ 1300,2150 };
	pickups[2].transform.m_position = vec2{ 1550,-800 };
	pickups[3].transform.m_position = vec2{ 350,1750 };

	blocks[1].transform.m_facing = -1.57; // 90 degree angle
	blocks[5].transform.m_facing = .7;
	blocks[6].transform.m_facing = .7;
	blocks[7].transform.m_facing = .7;
	blocks[8].transform.m_facing = .7;
	blocks[9].transform.m_facing = -.57;
	blocks[10].transform.m_facing = -.57;
	blocks[12].transform.m_facing = -1.57;
	blocks[13].transform.m_facing = -1.57;
	blocks[14].transform.m_facing = -1.57;
	blocks[15].transform.m_facing = -1.57;
	blocks[16].transform.m_facing = -1.57;
	blocks[17].transform.m_facing = -1.57;
	blocks[20].transform.m_facing = -1.57;
	blocks[21].transform.m_facing = -1.57;
	blocks[22].transform.m_facing = -1.57;
	blocks[23].transform.m_facing = -1.57;
	blocks[24].transform.m_facing = -1.57;
	blocks[25].transform.m_facing = .7;
	blocks[26].transform.m_facing = .7;
	blocks[27].transform.m_facing = .7;
	blocks[28].transform.m_facing = -.7;
	blocks[29].transform.m_facing = -.7;
	blocks[30].transform.m_facing = .7;
	blocks[31].transform.m_facing = .7;
	blocks[32].transform.m_facing = -.7;
	blocks[33].transform.m_facing = -.7;
	blocks[36].transform.m_facing = -.7;
	blocks[37].transform.m_facing = -1.57;
	blocks[38].transform.m_facing = .7;
	blocks[40].transform.m_facing = -1.57;
	blocks[43].transform.m_facing = -1.57;
	

	blocks[0].transform.m_position = vec2{ -50,0 }; //leftside
	blocks[1].transform.m_position = vec2{ 0,0 };
	blocks[2].transform.m_position = vec2{ -50,0 }; // rightside
	blocks[3].transform.m_position = vec2{ -50,500 }; // L
	blocks[4].transform.m_position = vec2{ 500,500 }; // rightside
	blocks[5].transform.m_position = vec2{ -50,1000 }; // L
	
	blocks[6].transform.m_position = vec2{ 500,1000 }; // R
	blocks[7].transform.m_position = vec2{ -372,1385 }; // L
	blocks[8].transform.m_position = vec2{ 175,1390 }; // R
	blocks[9].transform.m_position = vec2{ -694,1770 }; // L
	blocks[10].transform.m_position = vec2{ -170,1780 }; // R
	blocks[10].transform.m_scale = vec2{ 10,9 };
	blocks[11].transform.m_position = vec2{ -434,2170 }; 
	blocks[12].transform.m_position = vec2{ -404,2670 }; //L
	blocks[13].transform.m_position = vec2{ 70,2180 }; // Rdww
	blocks[14].transform.m_position = vec2{ 104,2670 };
	blocks[15].transform.m_position = vec2{ 570,2180 }; // R
	blocks[16].transform.m_position = vec2{ 604,2670 }; //L
	blocks[17].transform.m_position = vec2{ 1104,2670 }; // L
	blocks[18].transform.m_position = vec2{ 1604,2270 };
	blocks[19].transform.m_position = vec2{ 1604,1770 };
	blocks[20].transform.m_position = vec2{ 1104,1770 }; 
	blocks[21].transform.m_position = vec2{ 604,1770 };
	blocks[22].transform.m_position = vec2{ 1104,1370 };
	blocks[23].transform.m_position = vec2{ 604,1370 };
	blocks[24].transform.m_position = vec2{ 254,1370 };
	blocks[24].transform.m_scale = vec2{ 10,7 };
	blocks[25].transform.m_position = vec2{ 1904,970 };
	blocks[26].transform.m_position = vec2{ 2000,1430 };
	blocks[27].transform.m_position = vec2{ 2330,1050 };
	blocks[28].transform.m_position = vec2{ 1550,630 };
	blocks[29].transform.m_position = vec2{ 2060,700 };
	blocks[30].transform.m_position = vec2{ 1860,200 };
	blocks[31].transform.m_position = vec2{ 2360,270 };
	blocks[32].transform.m_position = vec2{ 1520,-170 };
	blocks[33].transform.m_position = vec2{ 2060,-100 };
	blocks[34].transform.m_position = vec2{ 1520,-640 };
	blocks[35].transform.m_position = vec2{ 2060,-630 };
	blocks[36].transform.m_position = vec2{ 1800,-1000 };
	
	blocks[37].transform.m_position = vec2{ 1300,-1000 };
	blocks[38].transform.m_position = vec2{ 1270,-1040 };
	blocks[39].transform.m_position = vec2{ 940,-630 };
	blocks[40].transform.m_position = vec2{ 450,0 }; //leftside
	blocks[41].transform.m_position = vec2{ 940,-498 };
	blocks[42].transform.m_position = vec2{ 1520,-150 };
	
	blocks[42].transform.m_scale = vec2{ 10,12 };///////////////////////////////
	blocks[43].transform.m_position = vec2{ 500,500 };// rightside   
	blocks[43].transform.m_scale = vec2{ 10,22 }; /////////////////////////////////////////////
	

	// fix doubled-up blocks for timer
}

void GameState::update(float deltaTime)
{

	
	camera.update(deltaTime, *this);

	track.Effect = false;
	track.time -= deltaTime;
	track.GoTime -= deltaTime;
	playerLapCollision(  player, lapline[0], lapline[1],track );
	
	if (track.GoTime > 0)
	{
		player.rigidbody.mass = 500000;
		
		
		if (track.GoTime < 4.f)
		{

			track.Go.m_color = YELLOW;
			track.Go.m_position = vec2{ 250, 500 };
			Red = true;
			Yellow = false;
		}
		if (track.GoTime < 1.f)
		{
			Green = false;
			Yellow = true;
			track.Go.m_color = GREEN;
			track.Go.m_position = vec2{ 250, 400 };
		}
		
	}
	if (track.GoTime < 0)
	{
		movement = true;
	
	}
		

	
	if (movement == true)
	{
		player.rigidbody.mass = 1;

		player.update(deltaTime, *this);
	}
	
	

	
	playerPickUpCollision(player, pickups[0], track);
	playerPickUpCollision2(player, pickups[1], track);
	playerPickUpCollision3(player, pickups[2], track);
	playerPickUpCollision4(player, pickups[3], track);
	
	for (int i = 0; i < BlocksNum; i++)
	{
		blocks[i].update(deltaTime, *this);
	}
	for (int i = 0; i < BlocksNum; i++)
	{
		playerObjectCollision(player, blocks[i], track);
	}
	if (track.time <= 0.f)
	{
		GameOver = true;
		
	}
	if (track.laps == 3 )
	{
		GameOver = true;
		w = 1;
	}
	
}

void GameState::draw()
{
	mat3 cam = camera.getCameraMatrix();
	
	player.draw(cam);
	lapline[0].draw(cam);
	lapline[1].draw(cam);
	
	if (track.GoTime > 0)
	{
		track.debugDrawGo(cam);

		if (Red == true)
		sfw::drawCircle(400, 600, 18, 4, BLACK);
		
		if (Yellow == true)
		sfw::drawCircle(400, 550, 18, 4, BLACK);

		if (Green == true)
		sfw::drawCircle(400, 500, 18, 4, BLACK);
	}
		
	
	

	if (track.Effect == true)
	{
		int Display = rand() % 3;

		if(Display == 0)
		player.drawEffect0(cam);

		if (Display == 1)
			player.drawEffect1(cam);

		if (Display == 2)
			player.drawEffect2(cam);
	}
	
	if (track.GoTime < 0)
	drawScore(d, track.laps, track.time);


	for (int i = 0; i < BlocksNum; i++)
	{
		blocks[i].draw(cam);
	}
	
		pickups[0].draw(cam, track);
		pickups[1].draw2(cam, track);
		pickups[2].draw3(cam, track);
		pickups[3].draw4(cam, track);
	
}

MenuState GameState::nextAppState()
{
	if (GameOver)
		return Enter_Depart;
	else return Game;
}

void GameState::exit()
{

}
