#pragma once
#include "Transform.h"

class PlanetaryRenderer
{
public:
	PlanetaryRenderer(unsigned r_color = 0xffffffff, float r_size = 20.f);

	unsigned int color;
	float size;

	void draw(Transform & planeTrans, const mat3 &T);
};