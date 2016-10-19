#include "PlanetaryRenderer.h"
#include "sfwdraw.h"

PlanetaryRenderer::PlanetaryRenderer(unsigned r_color, float r_size)
{
	color = r_color;
	size = r_size;
}

void PlanetaryRenderer::draw(Transform & planeTrans, const mat3 &T)
{
	mat3 glob = planeTrans.getGlobalTransform();

	vec2 pos = glob[2].xy;

	sfw::drawCircle(pos.x, pos.y, size, 3, color);
}
