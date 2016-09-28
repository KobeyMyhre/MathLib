#include "Transform.h"
#include "sfwdraw.h"

/*Transform::Transform()
{
	position.x = 0;
	position.y = 0;

	scale.x = 28;
	scale.y = 8;
	facing = 0;
}*/
Transform::Transform(float x, float y, float w, float h, float a) : position{ x,y }, scale{ w,h }, facing{a}
{
	position.x = x;
	position.y = y;
}
vec2 Transform::getDirection()
{
	return fromAngle(facing);
}

void Transform::setDirection(const vec2 & dir)
{
	facing = angle(dir);
}
 
void Transform::debugDaw()
{
	sfw::drawCircle(position.x, position.y, 12, 3,BLACK);
	/*sfw::drawCircle(position.x , position.y -24, 12);*/
	/*sfw::drawCircle(position.x +24, position.y, 12);
	sfw::drawCircle(position.x + 24, position.y - 24, 12);*/

	vec2 dirEnd = position + getDirection() * scale.x ;
	vec2 upEnd = position - perp(getDirection()) * scale.x;

	//vec2 derEnd = position + getDirection() * scale.x;
	vec2 ipEnd = position + perp(getDirection()) * scale.x;

	sfw::drawLine(position.x , position.y, dirEnd.x, dirEnd.y, BLACK);

	sfw::drawLine(position.x, position.y, upEnd.x, upEnd.y,BLACK);

	/*sfw::drawLine(position.x, position.y, derEnd.x, derEnd.y, WHITE);*/

	sfw::drawLine(position.x, position.y, ipEnd.x, ipEnd.y, BLACK);

	if (sfw::getKey('W'))
	{
		position += getDirection() * 5;
	}
	if (sfw::getKey('S'))
	{
		position -= getDirection() * 5;
	}
	if (sfw::getKey('A'))
	{
		facing += .1;
	}
	if (sfw::getKey('D'))
	{
		facing -= .1;
	}

	if (position.x >= 800)
	{
		position.x = 0;
	}
	else if (position.x <= 0)
	{
		position.x = 800;
	}
	else if (position.y >= 600)
	{
		position.y = 0;
	}
	else if (position.y <= 0)
	{
		position.y = 600;
	}
}
