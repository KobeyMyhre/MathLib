#include "sfwdraw.h"
#include "vec2.h"
#include "Transform.h"
#include "flops.h"
#include "Rigidbody.h"
#include "SpaceshipLocomotion.h"
#include "SpaceshipController.h"
void main()
{
	float W = 800, H = 800;
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
	/*vec2 player = { 400, 400 };
	vec2 playerVelcocity = { 0,0 };
	float playerAngle = 1.f;*/

	Transform playerTransform(400,400);
	playerTransform.scale = { 5,5 };
	Rigidbody playerRigidbody;
	
	SpaceshipLocomotion playerLoco;
	SpaceShipController Controls;
	while (sfw::stepContext())
	{
		float deltaTime = sfw::getDeltaTime();

		/*if (sfw::getKey('W')) playerRigidbody.velocity.y += 10.0f;
		if (sfw::getKey('S')) playerRigidbody.velocity.y -= 10.0f;
		if (sfw::getKey('A')) playerRigidbody.velocity.x -= 10.0f;
		if (sfw::getKey('D')) playerRigidbody.velocity.x += 10.0f;
		
		if (sfw::getKey('Q')) playerRigidbody.angularVelocity += 1.0f;
		if (sfw::getKey('E')) playerRigidbody.angularVelocity -= 1.0f;*/

		//playerRigidbody.integrate(playerTransform, deltaTime);

		playerRigidbody.integrate(playerTransform, deltaTime);
		playerTransform.debugDaw();

		
		if (playerTransform.position.x < 0) playerTransform.position.x = W;
		else if (playerTransform.position.x > W)playerTransform.position.x = 0;
		if (playerTransform.position.y < 0) playerTransform.position.y = H;
		else if (playerTransform.position.y > H) playerTransform.position.y = 0;

		playerLoco.update(playerTransform, playerRigidbody);
		Controls.update(playerLoco);
		playerRigidbody.debugDraw(playerTransform);


		}
	

	
	
	sfw::termContext();
}