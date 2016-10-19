#include "Tail.h"

#include "sfwdraw.h"

void Tail::draw(Transform& targetTrans, Rigidbody & targetRbody)
{
	vec2 p = targetTrans.m_position;
	vec2 v = p - -(targetRbody.velocity);
	vec2 a = targetRbody.acceleration + p;

	///*-------SPACESHIP-------*/
	sfw::drawLine(p.x, p.y, v.x, v.y, BLACK);
	sfw::drawCircle(v.x, v.y, 5, 3, GREEN);





	/*if (sfw::getKey('A') )
	{
		targetTrans.m_facing += .1;
		
		targetTrans.m_facing /= 1.12;
	}
	if (sfw::getKey('D'))
	{
		targetTrans.m_facing -= .1;

		targetTrans.m_facing /= 1.12;
	}*/
	

	
	/*while (sfw::getKey('W'))
	{
	m_facing -= 0.1;
	}
	while (sfw::getKey('W'))
	{
	m_facing -= 0.1;
	}*/




	/*targetTrans.m_facing /= 1.2;*/

	
}
