#include "PlayerShip.h"
#include "GameState.h"

PlayerShip::PlayerShip()
{
	vec2 hullVrts[] = { { -10 , 5 },
						{ 3,11 },
						{ 7,9 },
						{ 7, -9 },
						{ 3, -11 },
						{ -10, -5 } };


	/*hull  Hull[6];
	Hull[0] = hull(hullVrts0, 6);
	Hull[1] = hull(hullVrts0, 6);
	Hull[2] = hull(hullVrts0, 6);
	Hull[3] = hull(hullVrts0, 6);
	Hull[4] = hull(hullVrts0, 6);
	Hull[5] = hull(hullVrts0, 6);*/




	collider = Collider(hullVrts, 6);
	
	
	transform.m_scale = vec2{ 5,5 };

}

void PlayerShip::update(float deltaTime, GameState & gs)
{
	spaceshiplocomotion.update(transform, rigidbody);
	rigidbody.integrate(transform, deltaTime);
	spaceshipcontroller.update(spaceshiplocomotion);
	// gravity
	/*rigidbody.addForce(vec2{ 0,-10 });*/

}

void PlayerShip::draw(const mat3 &camera)
{
	transform.debugDaw(camera);
	//collider.debugDraw(camera, transform);
	shiprender.draw(transform, camera);

	
	/*rigidbody.debugDraw(transform, camera);*/
}

void PlayerShip::drawEffect2(const mat3 & camera)
{
	shiprender.drawEffect2(transform, camera);
}

void PlayerShip::drawEffect1(const mat3 & camera)
{
	shiprender.drawEffect1(transform, camera);
}

void PlayerShip::drawEffect0(const mat3 & camera)
{
	shiprender.drawEffect0(transform, camera);
}
