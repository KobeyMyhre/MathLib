#pragma once
#include "shapes.h"
#include "Collider.h"
void drawCircle(const circle &c, unsigned color);
void drawAABB(const AABB &B, unsigned color);
void drawPlane(const plane &A, unsigned color);
void drawHull(const hull &h, unsigned color);