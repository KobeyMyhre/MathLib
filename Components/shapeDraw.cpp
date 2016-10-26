#include "shapeDraw.h"
#include "sfwdraw.h"
#include "Transform.h"
void drawCircle(const circle & c, unsigned color)
{
	sfw::drawCircle(c.pos.x, c.pos.y, c.radius,12, color);
}

void drawAABB(const AABB & B, unsigned color)
{
	//mat3 glob = T * obj.getGlobalTransform();
	//vec3 p1 = glob * vec3{ B.min().x,B.min().y, 1 }; // bottom left
	//vec3 p2 = glob * vec3{ B.min().x,B.max().y, 1 }; // top left
	//vec3 p3 = glob * vec3{ B.max().x,B.max().y, 1 }; // top right
	//vec3 p4 = glob * vec3{ B.max().x,B.min().y, 1 }; // bottom right



	sfw::drawLine(B.min().x , B.min().y, B.min().x, B.max().y, color);
	sfw::drawLine(B.min().x, B.min().y, B.max().x, B.min().y, color);
	sfw::drawLine(B.max().x, B.max().y, B.max().x, B.min().y, color);
	sfw::drawLine(B.min().x, B.max().y, B.max().x, B.max().y, color);

	/*sfw::drawLine(p1.x, p1.y, p2.x, p2.y, color);
	sfw::drawLine(p2.x, p2.y, p3.x, p3.y, color);
	sfw::drawLine(p4.x, p4.y, p3.x, p3.y, color);
	sfw::drawLine(p1.x, p1.y, p4.x, p4.y, color);*/
	
}
