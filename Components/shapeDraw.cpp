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

void drawPlane(const plane & A, unsigned color)
{

	vec2 L = -perp(A.dir);
	vec2 R = -perp(L);

	sfw::drawCircle(A.pos.x, A.pos.y, 6, 6, color);
	sfw::drawLine(A.pos.x, A.pos.y, (A.dir.x * 60 + A.pos.x)  , (A.dir.y * 60 + A.pos.y) , color);
	sfw::drawLine(A.pos.x, A.pos.y, (L.x * 30 + A.pos.x), (L.y * 30 + A.pos.y), color);
	sfw::drawLine(A.pos.x, A.pos.y, (R.x * 60 + A.pos.x), (R.y * 60 + A.pos.y), color);
	/*sfw::drawLine(A.pos.x, A.pos.y, ( A.pos.x - A.dir.x * 60) , ( A.pos.y - A.dir.y * 60 ) , color);*/
	//sfw::drawLine(A.pos.x, A.pos.y, Q.x , Q.y , color);
	//sfw::drawLine(A.pos.x, A.dir.y, A.dir.x, A.pos.y, color);
	//sfw::drawLine(A.dir.x, A.dir.y, A.pos.y, A.pos.x, color);
	//sfw::drawLine(A.pos.x, A.pos.y, A.dir.x, A.dir.y, color);
}

void drawHull(const hull & h, unsigned color)
{
	for (int i = 0; i < h.size; i++)
	{
		sfw::drawLine(h.vertices[i].x, h.vertices[i].y, h.vertices[(i + 1) % h.size].x, h.vertices[(i + 1) % h.size].y, color);
		if (i >= h.size - 1)
		{
			sfw::drawLine(h.vertices[i].x, h.vertices[i].y, h.vertices[0].x, h.vertices[0].y, color);
		}
	}


}
