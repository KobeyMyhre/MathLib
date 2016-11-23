#include "PickUps.h"
#include "sfwdraw.h"
#include "TrackManager.h"
PickUps::PickUps()
{
	vec2 hullvrts[] = { { 0,0 },{ -1,0 },{ -2,1 }, { -2,2 }, {-1,3}, {0,3}, {1,2}, {1,1} };

	collider = Collider(hullvrts, 8);
	transform.m_scale = vec2{ 10,10 };
}

void PickUps::update(float deltaTime, GameState & gs)
{
}

void PickUps::draw(const mat3 & camera, Track &track)
{
	
	if (track.PickedUp == false)
	{
		collider.debugDrawHull(camera, transform, CYAN);
	}
	

}
void PickUps::draw2(const mat3 & camera, Track &track)
{

	if (track.PickedUp2 == false)
	{
		collider.debugDrawHull(camera, transform, CYAN);
	}


}
void PickUps::draw3(const mat3 & camera, Track &track)
{

	if (track.PickedUp3 == false)
	{
		collider.debugDrawHull(camera, transform, CYAN);
	}


}
void PickUps::draw4(const mat3 & camera, Track &track)
{

	if (track.PickedUp4 == false)
	{
		collider.debugDrawHull(camera, transform, CYAN);
	}


}
