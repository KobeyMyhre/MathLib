#include "sfwdraw.h"
#include "vec2.h"
#include "Transform.h"
#include "flops.h"
#include "Rigidbody.h"
#include "SpaceshipLocomotion.h"
#include "SpaceshipController.h"
#include "PlanetaryMotor.h"
#include "Tail.h"

void main()
{
	float W = 800, H = 800;
	sfw::initContext(W, H);
	float steps = 100;

	Transform NunTransform;
	NunTransform.m_position = vec2{ 75, 100 };
	
	Rigidbody NunRbody;
	PlanetaryMotor NunMotor;
	NunMotor.m_roatationSpeed = .001;
	NunMotor.m_maxroatSpeed = .002;
	
	
	Transform NlutoTransform;
	NlutoTransform.m_position = vec2{ 100, 75 };
	NlutoTransform.m_parent = &NunTransform;
	Rigidbody NlutoRbody;
	PlanetaryMotor NlutoMotor;
	NlutoMotor.m_roatationSpeed = .001;
	NlutoMotor.m_maxroatSpeed = .002;
	

	Transform sunTransform;
	sunTransform.m_position = vec2{ 400, 400 };
	Rigidbody sunRbody;
	PlanetaryMotor sunMotor;
	sunMotor.m_roatationSpeed = .005;
	sunMotor.m_maxroatSpeed = .01;

	Transform plutoTransform;
	plutoTransform.m_position = vec2{ 50, 0 };
	plutoTransform.m_parent = &sunTransform;
	Rigidbody plutoRbody;
	PlanetaryMotor plutoMotor;
	plutoMotor.m_roatationSpeed = .002;
	plutoMotor.m_maxroatSpeed = .003;
	
	Transform plutoMoonTransform;
	plutoMoonTransform.m_position = vec2{ 25, 0 };
	plutoMoonTransform.m_parent = &plutoTransform;
	NunTransform.m_parent = &plutoMoonTransform;

	plutoMoonTransform.m_color = CYAN;
	sunTransform.m_color = RED;
	 NlutoTransform.m_color = GREEN;
	 NunTransform.m_color = WHITE;
	 plutoTransform.m_color = YELLOW;
	/*--------Tails---------
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
	SpaceshipController Joint3Controller(' ', ' ', 'C', 'Z', 'B');*/
	/* ---------Tail function---------
	Transform Tail1(5, 0);
	Transform Tail2(5, 0);
	Transform Tail3(5, 0);
	Transform Tail4(5, 0);
	Rigidbody Tail1R;
	Rigidbody Tail2R;
	Rigidbody Tail3R;
	Rigidbody Tail4R;
	Tail tail1;
	Tail tail2;
	Tail tail3;
	Tail tail4;
	Tail1.m_parent = &playerTransform;
	Tail2.m_parent = &Tail1;
	Tail3.m_parent = &Tail2;
	Tail4.m_parent = &Tail3;*/
	
	/*----------SPACESHIP--------*/
	Transform playerTransform(400,400);
	Transform ST1(-1, 4);
	Transform ST2(-1, -4);
	
	
	
	ST1.m_parent = &playerTransform;
	ST2.m_parent = &playerTransform;

	playerTransform.m_scale = { 5,5 };
	Rigidbody playerRigidbody;
	
	
	SpaceshipLocomotion playerLoco;
	SpaceshipController Controls('W','S', 'A', 'D', ' ');
	while (sfw::stepContext())
	{
		float deltaTime = sfw::getDeltaTime();

		
		// ----------SPACESHIP----------
		playerRigidbody.integrate(playerTransform, deltaTime);
		playerTransform.debugDrawShip();

		
		if (playerTransform.m_position.x < 0) playerTransform.m_position.x = W;
		else if (playerTransform.m_position.x > W)playerTransform.m_position.x = 0;
		if (playerTransform.m_position.y < 0) playerTransform.m_position.y = H;
		else if (playerTransform.m_position.y > H) playerTransform.m_position.y = 0;

		playerLoco.update(playerTransform, playerRigidbody);
		Controls.update(playerLoco);
		playerRigidbody.debugDraw(playerTransform);
		
		
		ST1.debugDrawShip();
		ST2.debugDrawShip();
		
		sunMotor.update(sunRbody);
		sunRbody.integrate(sunTransform,deltaTime );
		sunTransform.debugDaw();
		plutoMotor.update(plutoRbody);
		plutoRbody.integrate(plutoTransform, deltaTime);
		plutoTransform.debugDaw();
		plutoMoonTransform.debugDaw();

		NunMotor.update(NunRbody);
		NunRbody.integrate(NunTransform, deltaTime);
		NunTransform.debugDaw();
		NlutoMotor.update(NlutoRbody);
		NlutoRbody.integrate(NlutoTransform, deltaTime);
		NlutoTransform.debugDaw();
		
		/*---------Tail Function------
		Tail1.debugDaw();
		Tail2.debugDaw();
		Tail3.debugDaw();
		tail1.draw(Tail1, Tail1R);
		tail2.draw(Tail2, Tail2R);
		tail3.draw(Tail3, Tail3R);
		tail4.draw(Tail4, Tail4R);
		Tail1.debugDaw();
		Tail2.debugDaw();
		Tail3.debugDaw();
		Tail4.debugDaw();
		tail1.draw(playerTransform, playerRigidbody);*/

		

		/*
		---------Tails--------
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
*/
		}
	

	
	
	sfw::termContext();
}