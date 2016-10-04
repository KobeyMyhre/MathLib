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

	scale.x = w;
	scale.y = h;

	facing = a;
}
vec2 Transform::getDirection() const
{
	return fromAngle(facing);
}

void Transform::setDirection(const vec2 & dir)
{
	facing = angle(dir);
}
 
void Transform::debugDaw() const
{
	sfw::drawCircle(position.x, position.y, 12, 3, BLACK);
	sfw::drawCircle(position.x, position.y , 6, 1, RED);


	vec2 dirEnd = position + getDirection() * scale.x * 4;
	vec2 upEnd = position - perp(getDirection()) * scale.x * 4 ;

	
	sfw::drawLine(position.x, position.y, dirEnd.x, dirEnd.y, RED);
	sfw::drawLine(position.x, position.y, upEnd.x, upEnd.y, RED);

	//vec2 ipEnd = position + perp(getDirection()) * scale.x;

	/*sfw::drawLine(position.x , position.y, dirEnd.x, dirEnd.y, BLACK);

	sfw::drawLine(position.x, position.y, upEnd.x, upEnd.y,BLACK);*/

	/*sfw::drawLine(position.x, position.y, derEnd.x, derEnd.y, WHITE);*/

	/*sfw::drawLine(position.x, position.y, ipEnd.x, ipEnd.y, BLACK);*/

	
}
