#pragma once
#include "vec2.h"
#include "mat3.h"
#include "shapes.h"

class Transform
{
public:
	/*Transform();*/
	Transform(float x = 0, float y = 0 , float w = 1, float h = 1, float a = 0, unsigned c = 0 );
	vec2 m_position;
	vec2 m_scale;
	float m_facing;
	unsigned m_color;

	Transform *m_parent;

	

	vec2 getUp() const;
	vec2 getDirection() const;
	void setDirection(const vec2 &dir);

	vec2 getGlobalPosition() const;
	vec2 getGlobalright() const;
	vec2 getGlobalUp() const;
	float getGlobalAngle() const;

	mat3 getGlobalTransform() const;
	mat3 getLocalTransform() const;

	
	
	void debugDaw(const mat3 &T = mat3Identity()) const;
	void debugDrawShip(const mat3 &T = mat3Identity()) const;
};