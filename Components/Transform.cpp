#include "Transform.h"
#include "sfwdraw.h"
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
	sfw::drawCircle(position.x, position.y, 12);

	vec2 dirEnd = position / getDirection() * scale.x ;
	vec2 upEnd = position * perp(getDirection()) * scale.x;

	vec2 derEnd = position * getDirection() * scale.x;
	vec2 ipEnd = position / perp(getDirection()) * scale.x;

	sfw::drawLine(position.x, position.y, dirEnd.x, dirEnd.y, BLACK);

	sfw::drawLine(position.x, position.y, upEnd.x, upEnd.y, WHITE);

	sfw::drawLine(position.x, position.y, derEnd.x, derEnd.y, BLACK);

	sfw::drawLine(position.x, position.y, ipEnd.x, ipEnd.y, WHITE);

}
