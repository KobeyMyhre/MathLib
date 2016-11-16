#include "GameState.h"
#include "objectCollision.h"
#include "sfwdraw.h"
#include "Laps.h"
#include "LapLine.h"

int GameState::laps = 0;

void GameState::play()
{
	if (d == -1)
	{
		d = sfw::loadTextureMap("./res/fontmap.png", 16, 16);
	}

	player.transform.m_position = vec2{ 200,200 };
	player.transform.m_facing = -1.57;
	lapline.transform.m_position = vec2{ 600,0 };
	



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
	blocks[43].transform.m_facing = .7;
	blocks[44].transform.m_facing = -1.57;
	blocks[45].transform.m_facing = -1.57;
	blocks[46].transform.m_facing = .7;

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
	blocks[11].transform.m_position = vec2{ -404,2170 }; 
	blocks[12].transform.m_position = vec2{ -404,2670 }; //L
	blocks[13].transform.m_position = vec2{ 70,2180 }; // Rdww
	blocks[14].transform.m_position = vec2{ 104,2670 };
	blocks[15].transform.m_position = vec2{ 570,2180 }; // R
	blocks[16].transform.m_position = vec2{ 604,2670 }; //L
	blocks[17].transform.m_position = vec2{ 1104,2670 }; // L
	blocks[18].transform.m_position = vec2{ 1604,2170 };
	blocks[19].transform.m_position = vec2{ 1604,1770 };
	blocks[20].transform.m_position = vec2{ 1104,1770 }; 
	blocks[21].transform.m_position = vec2{ 604,1770 };
	blocks[22].transform.m_position = vec2{ 1104,1370 };
	blocks[23].transform.m_position = vec2{ 604,1370 };
	blocks[24].transform.m_position = vec2{ 314,1370 };
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
	blocks[42].transform.m_position = vec2{ 1520,-500 };
	blocks[43].transform.m_position = vec2{ 1520,0 };
	blocks[44].transform.m_position = vec2{ 500,500 }; // rightside
	blocks[45].transform.m_position = vec2{ 700,500 }; // rightside
	blocks[46].transform.m_position = vec2{ 1470,57 };
}

void GameState::update(float deltaTime)
{
	player.update(deltaTime, *this);
	camera.update(deltaTime, *this);
	playerLapCollision(player, lapline);


	for (int i = 0; i < BlocksNum; i++)
	{
		blocks[i].update(deltaTime, *this);
	}
	for (int i = 0; i < BlocksNum; i++)
	{
		playerObjectCollision(player, blocks[i]);
	}
	/*for (int i = 0; i < 2; i++)
		for(int j = 0; j < 2; j++)
	{
		ObjectCollision(asteroid[i], asteroid[j]);
	}*/
}

void GameState::draw()
{
	mat3 cam = camera.getCameraMatrix();
	
	player.draw(cam);
	lapline.draw(cam);

	drawScore(d, laps, 0);
	for (int i = 0; i < BlocksNum; i++)
	{
		blocks[i].draw(cam);
	}
}

void GameState::exit()
{

}
