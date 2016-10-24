#include "ShipRenderer.h"
#include "sfwdraw.h"
ShipRenderer::ShipRenderer()
{
	
	color = GREEN;
}

void ShipRenderer::draw(Transform & ship, const mat3 & T)
{
	mat3 glob = T * ship.getGlobalTransform();
	vec3 F = glob * vec3{-8,0,1};
	vec3 L = glob * vec3{0,-4,1};
	vec3 R = glob * vec3{ 0, 4,1};

	vec3 P1 = glob * vec3{ 0,-2,1 };
	vec3 P2 = glob * vec3{ 0, 2,1 };
	vec3 P3 = glob * vec3{ 14,0,1 };

	vec3 H1 = glob * vec3{ -4,-1,1 };
	vec3 H2 = glob * vec3{ -4,1,1 };
	vec3 H3 = glob * vec3{ -5,1.5,1 }; //R
	vec3 H4 = glob * vec3{ -5,-1.5,1 }; //L

	vec3 C1 = glob * vec3{ 1,-3,1 };
	vec3 C2 = glob * vec3{ 1, 3,1 };

	sfw::drawLine(F.x, F.y, H3.x, H3.y, GREEN);
	sfw::drawLine(F.x, F.y, H4.x, H4.y, GREEN);
	sfw::drawLine(R.x, R.y, H3.x, H3.y, BLACK);
	sfw::drawLine(L.x, L.y, H4.x, H4.y, BLACK);

	sfw::drawLine(L.x, L.y, P1.x, P1.y, BLACK);
	sfw::drawLine(R.x, R.y, P2.x, P2.y, BLACK);
	sfw::drawLine(P1.x, P1.y, P3.x, P3.y, BLACK);
	sfw::drawLine(P2.x, P2.y, P3.x, P3.y, BLACK);

	sfw::drawLine(H1.x, H1.y, H2.x, H2.y, GREEN);
	sfw::drawLine(H1.x, H1.y, H4.x, H4.y, GREEN);
	sfw::drawLine(H2.x, H2.y, H3.x, H3.y, GREEN);
	

	sfw::drawCircle(C1.x, C1.y, 2, 4, RED);
	sfw::drawCircle(C2.x, C2.y, 2, 4, RED);
}


