#include "sfwdraw.h"
#include "vec2.h"
#include "Transform.h"
#include "flops.h"
void main()
{
	float W = 1200, H = 1200;
	sfw::initContext(W,H);
	float steps = 100;
	/*Transform player;
	*/

	

	/*player.position = vec2{ 400,300 };
	player.facing = deg2rad(45);
	player.setDirection(.5f);

	player.facing = deg2rad(45);
	player.scale = vec2{ 35,15 };*/


	

	/*vec2    start = { 200, 300 },
		end = { 900, 800 },
		mid = { 0,  1100 };*/
	vec2 player = { 400, 400 };
	vec2 playerVelcocity = { 0,0 };
	float playerAngle = 1.f;
	while (sfw::stepContext())
	{
		/*player.debugDaw();*/
		sfw::drawCircle(player.x, player.y, 5.f);
		player += playerVelcocity * sfw::getDeltaTime();
		player += fromAngle(playerAngle) * sfw::getDeltaTime();
	

		/*if (playerVelcocity.x >= 15.f || playerVelcocity.x <= -15.f)
		{
			playerVelcocity.x = 15.f;
		}

		if (playerVelcocity.y >= 15.f || playerVelcocity.y <= -15.f)
		{
			playerVelcocity.y = 15.f;
		}*/
		/*if (playerVelcocity.x >= -6.f)
		{
			playerVelcocity.x = -6.f;
		}

		if (playerVelcocity.y >= -6.f)
		{
			playerVelcocity.y = -6.f;
		}*/


		if (sfw::getKey('S')) playerVelcocity.y -=  5.f;
		if (sfw::getKey('W'))playerVelcocity.y +=  5.f ;
		if (sfw::getKey('A')) playerVelcocity.x -=  5.f;
		if (sfw::getKey('D')) playerVelcocity.x += 5.f;

		if (player.x < 0) player.x = W;
		else if (player.x > W) player.x = 0;
		if (player.y < 0) player.y = H;
		else if (player.y > H) player.y = 0;


		}
	

	
	
	sfw::termContext();
}