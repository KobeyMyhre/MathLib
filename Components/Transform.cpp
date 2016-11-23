#include "Transform.h"
#include "sfwdraw.h"
#include "Rigidbody.h"
#include "shapeDraw.h"

Transform::Transform(float x, float y, float w, float h, float a, unsigned c) : m_position{ x,y }, m_scale{ w,h }, m_facing{ a }, m_color{c}
{
	m_position.x = x;
	m_position.y = y;

	m_scale.x = w;
	m_scale.y = h;

	m_color = c;

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

vec2 Transform::getGlobalPosition() const
{
	return getGlobalTransform()[2].xy;
}

vec2 Transform::getGlobalright() const
{
	return getGlobalTransform()[0].xy;
}

vec2 Transform::getGlobalUp() const
{
	return getGlobalTransform()[1].xy;
}

float Transform::getGlobalAngle() const
{
	return angle(getGlobalright());
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
	vec3 parentpos = m_parent ? T * m_parent->getGlobalTransform()[2] : pos;
	
	
	// ---------SPACESHIP---------
	vec3 up = l * vec3{ -1,4,1 };
	vec3 down = l * vec3{ -1,-4,1 };
	/*sfw::drawCircle(pos.x, pos.y, 8, 3, m_color);*/
	/*sfw::drawCircle(pos.x, pos.y, 6, 1, GREEN); 
	sfw::drawLine(pos.x, pos.y, up.x, up.y , GREEN); 
	sfw::drawLine(pos.x  , pos.y , down.x , down.y , GREEN);*/ 
	//sfw::drawLine(parentpos.x, parentpos.y, pos.x, pos.y, BLACK);

	/*sfw::drawCircle(pos.x, pos.y, 8, 3, m_color);*/
	
	

	
	




	

	
}

void Transform::debugDrawGoX(const mat3 & T) const
{
	mat3 l = T * getGlobalTransform();
	vec3 pos = l[2];
	vec3 parentpos = m_parent ? T * m_parent->getGlobalTransform()[2] : pos;

	sfw::drawCircle(pos.x, pos.y, 18, 4, m_color);
	//sfw::drawCircle(400, 600, 18, 4, BLACK);

	vec2 L1 = vec2{ 370,470 };
	vec2 L2 = vec2{ 370,625 };
	vec2 L3 = vec2{ 430,625 };
	vec2 L4 = vec2{ 430, 470 };
	
	sfw::drawLine(L1.x, L1.y, L2.x, L2.y, BLACK);
	sfw::drawLine(L3.x, L3.y, L2.x, L2.y, BLACK);
	sfw::drawLine(L3.x, L3.y, L4.x, L4.y, BLACK);
	sfw::drawLine(L1.x, L1.y, L4.x, L4.y, BLACK);
}

void Transform::debugDrawShip(const mat3 & T) const
{
	mat3 l = T * getGlobalTransform();
	vec3 pos = l[2];
	vec3 parentpos = m_parent ? T * m_parent->getGlobalTransform()[2] : pos;


	// ---------SPACESHIP---------
	vec3 up = l * vec3{ -1,4,1 };
	vec3 down = l * vec3{ -1,-4,1 };
	sfw::drawCircle(pos.x, pos.y, 8, 3, BLACK);
	sfw::drawCircle(pos.x, pos.y, 6, 1, GREEN);
	sfw::drawLine(pos.x, pos.y, up.x, up.y, GREEN);
	sfw::drawLine(pos.x, pos.y, down.x, down.y, GREEN);
	sfw::drawLine(parentpos.x, parentpos.y, pos.x, pos.y, CYAN);

	sfw::drawCircle(pos.x, pos.y, 8, 3, BLACK);
	sfw::drawLine(parentpos.x, parentpos.y, pos.x, pos.y, CYAN);
}

void Transform::debugDrawEffect(const mat3 & T) const
{
	mat3 l = T * getGlobalTransform();
	vec3 pos = l[2];
	vec3 parentpos = m_parent ? T * m_parent->getGlobalTransform()[2] : pos;

	vec2 L1 = vec2{ -2,2 };
	vec2 L2 = vec2{ -3,3 };
	vec2 L3 = vec2{ -1,4 };

	vec2 LL1 = vec2{ 1,1 };
	vec2 LL2 = vec2{ 0,2 };
	vec2 LL3 = vec2{ 3,3 };

	sfw::drawLine(L1.x, L1.y, L2.x, L2.y, RED);
	sfw::drawLine(L2.x, L2.y, L3.x, L3.y, RED);

	sfw::drawLine(LL1.x, LL1.y, LL2.x, LL2.y, RED);
	sfw::drawLine(LL2.x, LL2.y, LL3.x, LL3.y, RED);

	//mat3 glob = T * ship.getGlobalTransform();
	//vec3 F = glob * vec3{ 0,-8,1 }; // Left-side
	//vec3 F1 = glob * vec3{ 0,8,1 }; // Right-side

	//vec3 L1 = glob * vec3{ 0,-4,1 }; // Visor
	//vec3 L2 = glob * vec3{ 0,4,1 }; // 
	//vec3 L3 = glob * vec3{ 0.5,-4,1 }; // Visor
	//vec3 L4 = glob * vec3{ 0.5,4,1 }; //

	//vec3 F2 = glob * vec3{ -10,-5,1 }; //Tips
	//vec3 F3 = glob * vec3{ -10,5,1 }; // Tips

	//vec3 F4 = glob * vec3{ 3,-11,1 }; // Side
	//vec3 F5 = glob * vec3{ 3,11,1 }; // Side

	//vec3 F6 = glob * vec3{ 7,-9,1 }; // Back
	//vec3 F7 = glob * vec3{ 7, 9,1 }; // Back

	//vec3 F8 = glob * vec3{ 2,-8,1 }; // Left-side
	//vec3 F9 = glob * vec3{ 2,8,1 }; // Right-side


	//vec3 C1 = glob * vec3{ 1,-3,1 };
	//vec3 C2 = glob * vec3{ 1, 3,1 };



	//sfw::drawLine(F.x, F.y, L1.x, L1.y, BLACK);
	//sfw::drawLine(F1.x, F1.y, L2.x, L2.y, BLACK);
	//sfw::drawLine(L2.x, L2.y, L1.x, L1.y, CYAN);

	//sfw::drawLine(L4.x, L4.y, L3.x, L3.y, CYAN);

	//sfw::drawLine(F1.x, F1.y, F3.x, F3.y, BLACK);
	//sfw::drawLine(F.x, F.y, F2.x, F2.y, BLACK);
}
