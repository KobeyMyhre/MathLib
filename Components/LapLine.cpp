#include "LapLine.h"
#include "sfwdraw.h"
LapLine::LapLine()
{
	vec2 hullvrts[] = { 0,0, {0,10}, {-5, 5} };
	collider = Collider(hullvrts, 3);
	transform.m_scale = vec2{ 35,45 };
}

void LapLine::update(float deltaTime, GameState & gs)
{
	rigidbody.integrate(transform, deltaTime);
}

void LapLine::draw(const mat3 & camera)
{
	transform.debugDaw(camera);
	collider.debugDrawHull(camera, transform, GREEN);
}
