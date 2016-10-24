#include "PlanetaryRenderer.h"
#include "sfwdraw.h"

PlanetaryRenderer::PlanetaryRenderer(unsigned r_color, float r_size)
{
	color = r_color;
	size = r_size;
}

void PlanetaryRenderer::draw(Transform & planeTrans, const mat3 &T)
{
	mat3 glob = T * planeTrans.getGlobalTransform();

	float xRad = magnitude(glob * vec3{ size,0,0 });
	float yRad = magnitude(glob * vec3{ 0,size,0 });
	
	vec2 pos = glob[2].xy;

	float rad = xRad > yRad ? xRad : yRad;

	sfw::drawCircle(pos.x, pos.y, rad, 3, color);
}
