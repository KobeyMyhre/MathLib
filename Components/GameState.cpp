#include "GameState.h"
#include "objectCollision.h"
void GameState::play()
{
	player.transform.m_position = vec2{ 200,200 };
	player.transform.m_facing = 0;
	blocks[1].transform.m_facing = -1.57; // 90 degree angle

	blocks[0].transform.m_position = vec2{ -50,0 }; //leftside
	blocks[1].transform.m_position = vec2{ 0,0 };
	blocks[2].transform.m_position = vec2{ 500,0 }; // rightside
}

void GameState::update(float deltaTime)
{
	player.update(deltaTime, *this);
	camera.update(deltaTime, *this);

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
	for (int i = 0; i < BlocksNum; i++)
	{
		blocks[i].draw(cam);
	}
}
