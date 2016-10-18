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
	
	Transform Head(200, 200);
	Transform Joint1(25, 0);
	Transform Joint2(25, 0);
	Transform Joint3(25, 0);

	Joint1.m_parent = &Head;
	Joint2.m_parent = &Joint1;
	Joint3.m_parent = &Joint2;

	Rigidbody headRigidbody;
	SpaceshipLocomotion headLoco;
	SpaceshipController headController (' ', ' ', '1', '3', 'B');
	
	Rigidbody Joint1Rigidbody;
	SpaceshipLocomotion Joint1Loco;
	Rigidbody Joint2Rigidbody;
	SpaceshipLocomotion Joint2Loco;
	Rigidbody Joint3Rigidbody;
	SpaceshipLocomotion Joint3Loco;
	SpaceshipController Joint1Controller (' ', ' ', 'E', 'Q', ' ');
	SpaceshipController Joint2Controller(' ', ' ', 'D', 'A', 'B');
	SpaceshipController Joint3Controller(' ', ' ', 'C', 'Z', 'B');
	/*
	
	----------SPACESHIP--------
	Transform playerTransform(400,400);
	Transform ST1(-1, 4);
	Transform ST2(-1, -4);
	ST1.m_parent = &playerTransform;
	ST2.m_parent = &playerTransform;

	playerTransform.m_scale = { 5,5 };
	Rigidbody playerRigidbody;
	
	SpaceshipLocomotion playerLoco;
	SpaceShipController Controls('W' ,'S', 'D', 'A', ' ');*/
	while (sfw::stepContext())
	{
		float deltaTime = sfw::getDeltaTime();

		/*
		// ----------SPACESHIP----------
		playerRigidbody.integrate(playerTransform, deltaTime);
		playerTransform.debugDaw();

		
		if (playerTransform.m_position.x < 0) playerTransform.m_position.x = W;
		else if (playerTransform.m_position.x > W)playerTransform.m_position.x = 0;
		if (playerTransform.m_position.y < 0) playerTransform.m_position.y = H;
		else if (playerTransform.m_position.y > H) playerTransform.m_position.y = 0;

		playerLoco.update(playerTransform, playerRigidbody);
		Controls.update(playerLoco);
		playerRigidbody.debugDraw(playerTransform);

		ST1.debugDaw();
		ST2.debugDaw();*/

		Joint1.debugDaw();
		Joint2.debugDaw();
		Joint3.debugDaw();
		Head.debugDaw();


		headRigidbody.integrate(Head, deltaTime);
		headLoco.update(Head, headRigidbody);
		headController.update(headLoco);
		headRigidbody.debugDraw(Head);

		Joint1Rigidbody.integrate(Joint1, deltaTime);
		Joint1Loco.update(Joint1, Joint1Rigidbody);
		Joint1Rigidbody.debugDraw(Joint1);

		Joint2Rigidbody.integrate(Joint2, deltaTime);
		Joint2Loco.update(Joint2, Joint2Rigidbody);
		Joint2Rigidbody.debugDraw(Joint2);

		Joint3Rigidbody.integrate(Joint3, deltaTime);
		Joint3Loco.update(Joint3, Joint3Rigidbody);
		Joint3Rigidbody.debugDraw(Joint3);


		Joint1Controller.update(Joint1Loco);
		Joint2Controller.update(Joint2Loco);
		Joint3Controller.update(Joint3Loco);

		if (Head.m_position.x < 0) Head.m_position.x = W;
		else if (Head.m_position.x > W)Head.m_position.x = 0;
		if (Head.m_position.y < 0) Head.m_position.y = H;
		else if (Head.m_position.y > H) Head.m_position.y = 0;

		if (Head.m_position.x < 0) Head.m_position.x = W;
		else if (Head.m_position.x > W)Head.m_position.x = 0;
		if (Head.m_position.y < 0) Head.m_position.y = H;
		else if (Head.m_position.y > H) Head.m_position.y = 0;

		}
	

	
	
	sfw::termContext();
}