#include "WhirlPool.h"
#include "sfwdraw.h"
WhirlPool::WhirlPool()
{
	vec2 hullvrts[] = { { 0,4 },{ 2,4 },{ 3,3 },{ 3,1 },{2,0},{0,0},{-1,1},{-1,3} };

	collider = Collider(hullvrts, 8);
	transform.m_scale = vec2{ 10,10 };
}

void WhirlPool::update(float deltaTime, GameState & gs)
{
	rigidbody.integrate(transform, deltaTime);
}

void WhirlPool::draw(const mat3 & camera)
{
	transform.debugDrawWhirlPool(camera);
	collider.debugDrawHull(camera, transform, CYAN);
}
