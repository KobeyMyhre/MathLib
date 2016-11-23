#include "ShipRenderer.h"
#include "sfwdraw.h"
#include "shapeDraw.h"
ShipRenderer::ShipRenderer()
{
	
	color = GREEN;
}

void ShipRenderer::draw(Transform & ship, const mat3 & T)
{
	mat3 glob = T * ship.getGlobalTransform();
	vec3 F =  glob * vec3{0,-8,1}; // Left-side
	vec3 F1 = glob * vec3{0,8,1 }; // Right-side

	vec3 L1 = glob * vec3{ 0,-4,1 }; // Visor
	vec3 L2 = glob * vec3{ 0,4,1 }; // 
	vec3 L3 = glob * vec3{ 0.5,-4,1 }; // Visor
	vec3 L4 = glob * vec3{ 0.5,4,1 }; //

	vec3 F2 = glob * vec3{ -10,-5,1 }; //Tips
	vec3 F3 = glob * vec3{ -10,5,1 }; // Tips

	vec3 F4 = glob * vec3{ 3,-11,1 }; // Side
	vec3 F5 = glob * vec3{ 3,11,1 }; // Side

	vec3 F6 = glob * vec3{ 7,-9,1 }; // Back
	vec3 F7 = glob * vec3{ 7, 9,1 }; // Back

	vec3 F8 = glob * vec3{ 2,-8,1 }; // Left-side
	vec3 F9 = glob * vec3{ 2,8,1 }; // Right-side


	vec3 C1 = glob * vec3{ 1,-3,1 };
	vec3 C2 = glob * vec3{ 1, 3,1 };



	sfw::drawLine(F.x, F.y, L1.x, L1.y, BLACK);
	sfw::drawLine(F1.x, F1.y, L2.x, L2.y, BLACK);
	sfw::drawLine(L2.x, L2.y, L1.x, L1.y, CYAN);
	
	sfw::drawLine(L4.x, L4.y, L3.x, L3.y, CYAN);

	sfw::drawLine(F1.x, F1.y, F3.x, F3.y, BLACK);
	sfw::drawLine(F.x, F.y, F2.x, F2.y, BLACK);
	sfw::drawLine(F2.x, F2.y, F4.x, F4.y, BLACK);
	sfw::drawLine(F3.x, F3.y, F5.x, F5.y, BLACK);
	sfw::drawLine(F4.x, F4.y, F6.x, F6.y, BLACK);
	sfw::drawLine(F5.x, F5.y, F7.x, F7.y, BLACK);
	sfw::drawLine(F6.x, F6.y, F8.x, F8.y, BLACK);
	sfw::drawLine(F7.x, F7.y, F9.x, F9.y, BLACK);
	sfw::drawLine(F8.x, F8.y, F9.x, F9.y, BLACK);

	////////////
	//// Draw the non-aligned rectangle

	/*vec3 A = glob * vec3{-12,-12, 1};
	vec3 B = glob * vec3{-12, 12, 1 };
	vec3 C = glob * vec3{ 12, 12, 1 };
	vec3 D = glob * vec3{ 12, -12, 1 };

	sfw::drawLine(A.x, A.y, B.x, B.y, BLACK);
	sfw::drawLine(C.x, C.y, B.x, B.y, BLACK);
	sfw::drawLine(C.x, C.y, D.x, D.y, BLACK);
	sfw::drawLine(A.x, A.y, D.x, D.y, BLACK);*/

	/*drawCircle((glob * circle{ 0,0,12 }), MAGENTA);
	drawAABB((glob * AABB{ 0,0,6,6 }), CYAN);
	drawPlane((glob * plane{ 0,0, 0,1 }), WHITE);*/

	/*sfw::drawCircle(C1.x, C1.y, 2, 4, RED);
	sfw::drawCircle(C2.x, C2.y, 2, 4, RED);*/
}

void ShipRenderer::drawEffect0(Transform & planeTrans, const mat3 & T)
{
	mat3 glob = T * planeTrans.getGlobalTransform();

	vec3 L1 = glob * vec3{ 10,3 ,1};
	vec3 L2 = glob *vec3{ 12,6 ,1};
	vec3 L3 = glob *vec3{ 15,2 ,1};

	vec3 LL1 = glob * vec3{ 8,-14 ,1};
	vec3 LL2 = glob * vec3{ 1,-16 ,1};
	vec3 LL3 = glob * vec3{ 5,-24 ,1};

	vec3 QL1 = glob * vec3{ -9,-15 ,1 };
	vec3 QL2 = glob * vec3{ -15,-6 ,1 };
	vec3 QL3 = glob * vec3{ -18,8 ,1 };
	vec3 QL4 = glob * vec3{ -7,14 ,1 };

	sfw::drawLine(L1.x, L1.y, L2.x, L2.y, RED);
	sfw::drawLine(L2.x, L2.y, L3.x, L3.y, RED);

	sfw::drawLine(LL1.x, LL1.y, LL2.x, LL2.y, RED);
	sfw::drawLine(LL2.x, LL2.y, LL3.x, LL3.y, RED);

	sfw::drawLine(QL1.x, QL1.y, QL2.x, QL2.y, RED);
	sfw::drawLine(QL2.x, QL2.y, QL3.x, QL3.y, RED);
	sfw::drawLine(QL4.x, QL4.y, QL3.x, QL3.y, RED);
}

void ShipRenderer::drawEffect1(Transform & planeTrans, const mat3 & T)
{
	mat3 glob = T * planeTrans.getGlobalTransform();

	vec3 L1 = glob * vec3{ 9,2 ,1 };
	vec3 L2 = glob *vec3{ 11,4 ,1 };
	vec3 L3 = glob *vec3{ 10,-3 ,1 };
	vec3 L4 = glob *vec3{ 15,0 ,1 };

	vec3 QL1 = glob * vec3{ -3,-18 ,1 };
	vec3 QL2 = glob * vec3{ -5,-13 ,1 };
	vec3 QL3 = glob * vec3{ -7,-11 ,1 };
	vec3 QL4 = glob * vec3{ -11,-15 ,1 };
	vec3 QL5 = glob * vec3{ -13,-9 ,1 };

	sfw::drawLine(L1.x, L1.y, L2.x, L2.y, RED);
	sfw::drawLine(L2.x, L2.y, L3.x, L3.y, RED);
	sfw::drawLine(L3.x, L3.y, L4.x, L4.y, RED);
	
	sfw::drawLine(QL1.x, QL1.y, QL2.x, QL2.y, RED);
	sfw::drawLine(QL2.x, QL2.y, QL3.x, QL3.y, RED);
	sfw::drawLine(QL4.x, QL4.y, QL3.x, QL3.y, RED);
	sfw::drawLine(QL4.x, QL5.y, QL3.x, QL5.y, RED);
}

void ShipRenderer::drawEffect2(Transform & planeTrans, const mat3 & T)
{
	mat3 glob = T * planeTrans.getGlobalTransform();

	vec3 L1 = glob * vec3{ 0,12 ,1 };
	vec3 L2 = glob *vec3{ 3,15 ,1 };
	vec3 L3 = glob *vec3{ -2,17 ,1 };
	vec3 L4 = glob *vec3{ -8,13 ,1 };

	vec3 LL1 = glob * vec3{ 10,-4 ,1 };
	vec3 LL2 = glob * vec3{ 15,-8 ,1 };
	vec3 LL3 = glob * vec3{ 0,-17 ,1 };
	vec3 LL4 = glob * vec3{ 11,-18 ,1 };

	vec3 QL1 = glob * vec3{ -13,-1 ,1 };
	vec3 QL2 = glob * vec3{ -12,2 ,1 };
	vec3 QL3 = glob * vec3{ -15,6 ,1 };
	vec3 QL4 = glob * vec3{ -18,0 ,1 };
	vec3 QL5 = glob * vec3{ -16,-4 ,1 };

	sfw::drawLine(L1.x, L1.y, L2.x, L2.y, RED);
	sfw::drawLine(L2.x, L2.y, L3.x, L3.y, RED);
	sfw::drawLine(L4.x, L4.y, L3.x, L3.y, RED);

	sfw::drawLine(LL1.x, LL1.y, LL2.x, LL2.y, RED);
	sfw::drawLine(LL2.x, LL2.y, LL3.x, LL3.y, RED);
	sfw::drawLine(LL4.x, LL4.y, LL3.x, LL3.y, RED);

	sfw::drawLine(QL1.x, QL1.y, QL2.x, QL2.y, RED);
	sfw::drawLine(QL2.x, QL2.y, QL3.x, QL3.y, RED);
	sfw::drawLine(QL4.x, QL4.y, QL3.x, QL3.y, RED);
	sfw::drawLine(QL4.x, QL4.y, QL5.x, QL5.y, RED);

}

