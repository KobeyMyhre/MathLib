#pragma once

#include "Transform.h"
#include "mat3.h"

class ShipRenderer
{
public:
	unsigned color;
	ShipRenderer();

	void draw(Transform & planeTrans, const mat3 &T);
	
};