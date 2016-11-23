#include "ColliderObject.h"
#include "sfwdraw.h"
ColliderObj::ColliderObj()
{
	vec2 hullvrts[] = { {0,0}, {5,0}, {5,50}, {0,50} };

	collider = Collider(hullvrts, 4);
	transform.m_scale = vec2{ 10,10 };
	/*rigidbody.drag = 0.f;
	rigidbody.angularDrag = 0.f;
	rigidbody.mass = 10;*/


};
	



void ColliderObj::update(float deltaTime, GameState & gs)
{
	rigidbody.integrate(transform, deltaTime);
	
}

void ColliderObj::draw(const mat3 & camera)
{
	transform.debugDaw(camera);
	collider.debugDrawHull(camera, transform, GREEN);
	/*rigidbody.debugDraw(transform, camera);*/
}
