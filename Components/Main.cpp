#include "sfwdraw.h"
#include "vec2.h"
#include "Transform.h"
#include "flops.h"
#include "Rigidbody.h"
#include "SpaceshipLocomotion.h"
#include "SpaceshipController.h"
#include "PlanetaryMotor.h"
#include "Tail.h"
#include "PlanetaryRenderer.h"
#include "ShipRenderer.h"
#include "Collider.h"
#include <iostream>
#include "GameState.h"
#include "MenuState.h"
#include "departz.h"
#include "Option.h"
#include "TrackManager.h"

void main()
{
	float W = 800, H = 800;
	sfw::initContext(W, H);
	float steps = 100;
	int	d = sfw::loadTextureMap("./res/fontmap.png", 16, 16);


	GameState game;
	
	depart depart;
	option option;


	depart.init(d);
	option.init(d);



	MenuState state = Enter_Option;

	game.play();


	while (sfw::stepContext())
	{
		float deltaTime = sfw::getDeltaTime();
		switch (state)
		{

		case Enter_Option:
			option.play();
		case Option:
			option.step();
			option.draw();
			state = option.next();
			break;
		case Enter_Depart:
			depart.play(game.w);
		case Depart:
			depart.step();
			depart.draw();
			state = depart.next();
			break;


		case Enter_Game:
			//gs.isGameOver();
			game.play();
		case Game:
			game.update(deltaTime);
			game.draw();
			state = game.nextAppState();


			/*game.update(deltaTime);
			game.draw();*/

		}




		//sfw::termContext();
	}

}

	//Transform sunTransform;
	//sunTransform.m_position = vec2{ 400, 400 };
	//Rigidbody sunRbody;
	//sunRbody.angularDrag = 1.f;
	//PlanetaryMotor sunMotor;
	//sunMotor.m_roatationSpeed = 1.f;
	//PlanetaryRenderer sunRender(YELLOW, 75);

	//Transform NunTransform;
	//NunTransform.m_position = vec2{ -150, -150 };
	//NunTransform.m_scale = vec2{ 10,10 };
	//Rigidbody NunRbody;
	//NunRbody.angularDrag = 1.f;
	//PlanetaryMotor NunMotor;
	//NunMotor.m_roatationSpeed = 1.f;
	//NunTransform.m_parent = &sunTransform;
	//PlanetaryRenderer NunRender(WHITE, 67);
	//
	//
	//Transform NlutoTransform;
	//NlutoTransform.m_position = vec2{ 5, 5 };
	//NlutoTransform.m_parent = &NunTransform;
	//Rigidbody NlutoRbody;
	//NlutoRbody.angularDrag = 1.f;
	//PlanetaryMotor NlutoMotor;
	//NlutoMotor.m_roatationSpeed = 1.f;
	//PlanetaryRenderer NlutoRender(RED, 37);
	//


	//Transform plutoTransform;
	//plutoTransform.m_position = vec2{ -150, 50 };
	//plutoTransform.m_parent = &sunTransform;
	//Rigidbody plutoRbody;
	//plutoRbody.angularDrag = 1.f;
	//PlanetaryMotor plutoMotor;
	//plutoMotor.m_roatationSpeed = 1.f;
	//PlanetaryRenderer plutoRender(CYAN,60);
	//
	//Transform plutoMoonTransform;
	//plutoMoonTransform.m_position = vec2{ 25, 0 };
	//plutoMoonTransform.m_parent = &plutoTransform;
	//
	//PlanetaryRenderer plutoMoonRender(GREEN, 30);

	//Transform clutoTransform;
	//clutoTransform.m_position = vec2{ 150, 150 };
	//clutoTransform.m_parent = &sunTransform;
	//Rigidbody clutoRbody;
	//clutoRbody.angularDrag = 1.f;
	//PlanetaryMotor clutoMotor;
	//clutoMotor.m_roatationSpeed = 1.f;
	//PlanetaryRenderer clutoRender(YELLOW, 50);

	//Transform clutoMoonTransform;
	//clutoMoonTransform.m_position = vec2{ 33, 0 };
	//clutoMoonTransform.m_parent = &clutoTransform;
	//PlanetaryRenderer clutoMoonRender(YELLOW, 20);

	//Transform clutoMoon2Transform;
	//clutoMoon2Transform.m_position = vec2{ 33, 15 };
	//clutoMoon2Transform.m_parent = &clutoTransform;
	//PlanetaryRenderer clutoMoon2Render(YELLOW, 20);
	//
	// ----------SPACESHIP----------
		
		

		
		/*if (playerTransform.m_position.x < 0) playerTransform.m_position.x = W;
		else if (playerTransform.m_position.x > W)playerTransform.m_position.x = 0;
		if (playerTransform.m_position.y < 0) playerTransform.m_position.y = H;
		else if (playerTransform.m_position.y > H) playerTransform.m_position.y = 0;*/

		//CollisionData results = ColliderCollision(playerTransform, playerCollider, occluderTransform, occluderCollider);
	

		//StaticResolution(playerTransform, playerRigidbody, playerCollider, occluderTransform, occluderCollider);
		//DynamicResolution(playerTransform, playerRigidbody, playerCollider, occluderTransform, occluderRigidbody, occluderCollider,1.5);




		/*if (results.penetrationDepth >= 0)
		{
			vec2 mtv = results.penetrationDepth * results.collisionNormal;

			vec3 mtv3 = { mtv.x,mtv.y, 1 };
			
			mtv3 = inverse(playerTransform.getGlobalTransform()) * mtv3;

			mtv = mtv3.xy;
			playerTransform.m_position += mtv;

		}*/
		
		// UPDATE
		/*playerLoco.update(playerTransform, playerRigidbody);
		Controls.update(playerLoco);*/
		//sunMotor.update(sunRbody);
		//plutoMotor.update(plutoRbody);
		//NunMotor.update(NunRbody);
		//NlutoMotor.update(NlutoRbody);
		//clutoMotor.update(clutoRbody);

		//// Integrate
		//plutoRbody.integrate(plutoTransform, deltaTime);
		//sunRbody.integrate(sunTransform,deltaTime );
		//NunRbody.integrate(NunTransform, deltaTime);
		//NlutoRbody.integrate(NlutoTransform, deltaTime);
		///*playerRigidbody.integrate(playerTransform, deltaTime);*/
		//clutoRbody.integrate(clutoTransform, deltaTime);
		//occluderRigidbody.integrate(occluderTransform, deltaTime);
		//
		// DRAW
		

	/*	vec2 gp = playerTransform.getGlobalPosition();

		cameraPosition.m_position = lerp(cameraPosition.m_position, playerTransform.getGlobalPosition(), sfw::getDeltaTime()*10);

		mat3 proj = translate(400, 400) * scale(1, 1);
		mat3 view = inverse(cameraPosition.getGlobalTransform());

		mat3 camera = proj * view;*/

		
		//sunTransform.debugDaw(camera);
		//sunRender.draw(sunTransform, camera);
		//plutoRender.draw(plutoTransform, camera);
		//plutoMoonRender.draw(plutoMoonTransform, camera);
		//NunRender.draw(NunTransform,  camera);
		//NlutoRender.draw(NlutoTransform, camera);
		//clutoRender.draw(clutoTransform, camera);
		//clutoMoonRender.draw(clutoMoonTransform, camera);
		//clutoMoon2Render.draw(clutoMoon2Transform, camera);

		////SpaceShip.draw(playerTransform, camera);
		///*playerTransform.debugDaw(camera);*/
		//playerCollider.debugDraw(camera, playerTransform);
		//occluderCollider.debugDraw(camera, occluderTransform);
		///*playerRigidbody.debugDraw(playerTransform, camera);
		//playerTransform.debugDrawShip(camera);*/
		///*ST1.debugDrawShip(camera);
		//ST2.debugDrawShip(camera);*/

		
		
		
		
		
		
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
	
	///*----------SPACESHIP--------*/
	//Transform playerTransform(200,200);
	////playerTransform.m_scale = vec2{ 1,1 };	// TODO; remove me
	//Transform ST1(-1, 4);
	//Transform ST2(-1, -4);
	//
	//vec2 hullVrts[] = { {-10 , 5 },
	//					{ 3,11 },
	//					
	//					{7,9},
	//					{7, -9},
	//					
	//					{3, -11},
	//					{-10, -5} };
	//Collider playerCollider(hullVrts, 6);

	//Transform occluderTransform(0, 0);
	//occluderTransform.m_scale = vec2{ 8,8 };
	//Collider occluderCollider(hullVrts,6);
	//
	//ST1.m_parent = &playerTransform;
	//ST2.m_parent = &playerTransform;

	//playerTransform.m_scale = { 5,5 };
	//Rigidbody playerRigidbody;
	//Rigidbody occluderRigidbody;
	//ShipRenderer SpaceShip;
	//


	//SpaceshipLocomotion playerLoco;
	//SpaceshipController Controls('W','S', 'A', 'D', ' ');

	//Transform cameraPosition;