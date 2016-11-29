#include "SpeedBoost.h"
#include "sfwdraw.h"
SpeedBoost::SpeedBoost()
{
	vec2 hullvrts[] = { { 0,0 },{ 5,0 },{ 5,19 },{ 0,19 } };

	collider = Collider(hullvrts, 4);
	transform.m_scale = vec2{ 10,10 };
}

void SpeedBoost::update(float deltaTime, GameState & gs)
{
	rigidbody.integrate(transform, deltaTime);
}

void SpeedBoost::draw(const mat3 & camera)
{
	transform.debugDrawSpeed(camera);
	collider.debugDrawHull(camera, transform, MAGENTA);
}
