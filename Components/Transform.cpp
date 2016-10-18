#include "Transform.h"
#include "sfwdraw.h"
#include "Rigidbody.h"

Transform::Transform(float x, float y, float w, float h, float a) : m_position{ x,y }, m_scale{ w,h }, m_facing{a}
{
	m_position.x = x;
	m_position.y = y;

	m_scale.x = w;
	m_scale.y = h;

	m_facing = a;
	m_parent = nullptr;
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

mat3 Transform::getGlobalTransform() const
{
	if (m_parent == nullptr)
		return getLocalTransform();
	else
		return m_parent->getGlobalTransform() *getLocalTransform();
}

mat3 Transform::getLocalTransform() const
{
	mat3 S = scale(m_scale.x, m_scale.y);

	mat3 T = translate(m_position.x, m_position.y);

	mat3 R = rotation(m_facing);

	return  T  * R * S;
}
 
void Transform::debugDaw(const mat3 &T) const
{
	

	mat3 l = T * getGlobalTransform();
	vec3 pos = l[2];
	vec3 parentpos = m_parent ? m_parent->getGlobalTransform()[2] : pos;
	
	
	// ---------SPACESHIP---------
	/*vec3 up = l * vec3{ -1,4,1 };
	vec3 down = l * vec3{ -1,-4,1 };
	sfw::drawCircle(pos.x, pos.y, 8, 3, BLACK);
	sfw::drawCircle(pos.x, pos.y, 6, 1, GREEN); 
	sfw::drawLine(pos.x, pos.y, up.x, up.y , GREEN); 
	sfw::drawLine(pos.x  , pos.y , down.x , down.y , GREEN); 
	sfw::drawLine(parentpos.x, parentpos.y, pos.x, pos.y, BLACK);*/

	sfw::drawCircle(pos.x, pos.y, 8, 3, BLACK);
	sfw::drawLine(parentpos.x, parentpos.y, pos.x, pos.y, CYAN); 
	
	




	

	
}
