#include "Transform.h"
#include "sfwdraw.h"

/*Transform::Transform()
{
	m_position.x = 0;
	m_position.y = 0;

	m_scale.x = 28;
	m_scale.y = 8;
	m_facing = 0;
}*/
Transform::Transform(float x, float y, float w, float h, float a) : m_position{ x,y }, m_scale{ w,h }, m_facing{a}
{
	m_position.x = x;
	m_position.y = y;

	m_scale.x = w;
	m_scale.y = h;

	m_facing = a;
}
vec2 Transform::getUp() const
{
	return -perp(getDirection());
}
vec2 Transform::getDirection() const
{
	return fromAngle(m_facing);
}

void Transform::setDirection(const vec2 & dir)
{
	m_facing = angle(dir);
}

mat3 Transform::getLocalTransform() const
{
	mat3 S = scale(m_scale.x, m_scale.y);

	mat3 T = translate(m_position.x, m_position.y);

	mat3 R = rotation(m_facing);

	return  T * S * R;
}
 
void Transform::debugDaw(const mat3 &T) const
{
	

	mat3 l = T * getLocalTransform();
	vec3 pos = l[2];

	vec3 right = pos + l * vec3{ 1, 0, 0 };
	/*vec3 up = l * vec3{ 0,4,1 };*/

	vec2 dirEnd = m_position + getDirection() * m_scale.x * 4;
	/*vec2 upEnd = m_position - perp(getDirection()) * m_scale.x * 4 ;*/

	sfw::drawCircle(pos.x, pos.y, 12, 3, BLACK);
	sfw::drawCircle(pos.x, pos.y, 6, 1, RED);

	sfw::drawLine(pos.x, pos.y, right.x, right.y, RED);
	//sfw::drawLine(m_position.x, m_position.y, up.x, up.y, GREEN);

	/*sfw::drawLine(m_position.x, m_position.y, dirEnd.x, dirEnd.y, RED);*/
	/*sfw::drawLine(m_position.x, m_position.y, upEnd.x, upEnd.y, RED);*/

	/*vec2 ipEnd = m_position + perp(getDirection()) * m_scale.x;

	sfw::drawLine(m_position.x , m_position.y, dirEnd.x, dirEnd.y, BLACK);

	sfw::drawLine(m_position.x, m_position.y, upEnd.x, upEnd.y,BLACK);

	sfw::drawLine(m_position.x, m_position.y, dirEnd.x, dirEnd.y, WHITE);

	sfw::drawLine(m_position.x, m_position.y, ipEnd.x, ipEnd.y, BLACK);*/

	
}
