#include "sfwdraw.h"
#include "vec2.h"
#include "Transform.h"
#include "flops.h"
void main()
{
	sfw::initContext(1200,1200);
	//Transform trans;
	/*Transform trans(400, 300, 12, 12, 0);

	Transform T = Transform();
	trans.position = vec2{ 400,300 };
	int i = int();
	int j = int(4);
	int k(4);
	int l = { 4 };
	int m = 4;

	Transform tl = Transform(400, 300);
	Transform tn = { 400, 300 };
	Transform tm(400, 300);
	Transform tq{ 400,300 };

	trans.position = vec2{ 400,300 };
	trans.facing = deg2rad(45);


	trans.facing = deg2rad(45);
	trans.scale = vec2{ 35,15 };
	vec2 basis = { 40,0 };
	float ang_vec = 0;*/

	while (sfw::stepContext())
	{


		for (int i = 0; i < 100; ++i)
		{
			float x1 = i / 100.f;
			float x2 = (i + 1) / 100.f;

			float y1 = growFast(x1);
			float y2 = growFast(x2);

			x1 *= 400;
			x2 *= 800;
			y1 *= 400;
			y2 *= 800;

			sfw::drawLine(x1, y1, x2, y2);

		
		}

		for (int i = 0; i < 100; ++i)
		{
			float x1 = i / 100.f;
			float x2 = (i + 1) / 100.f;

			float y1 = growFaster(x1);
			float y2 = growFaster(x2);

			x1 *= 400;
			x2 *= 800;
			y1 *= 400;
			y2 *= 800;

			sfw::drawLine(x1, y1, x2, y2);


		}
		for (int i = 0; i < 100; ++i)
		{
			float x1 = 1 / 100.f;
			float x2 = (i + 1) / 100.f;

			float y1 = TriBS(x1);
			float y2 = TriBS(x2);

			x1 *= 800;
			x2 *= 800;
			y1 *= 800;
			y2 *= 800;

			sfw::drawLine(x1, y1, x2, y2);


		}
		for (int i = 0; i < 100; ++i)
		{
			float x1 = i / 100.f;
			float x2 = (i + 1) / 100.f;

			float y1 = bounceflip(x1);
			float y2 = bounceflip(x2);

			x1 *= 800;
			x2 *= 800;
			y1 *= 800;
			y2 *= 800;

			sfw::drawLine(x1, y1, x2, y2);


		}
		for (int i = 0; i < 100; ++i)
		{
			float x1 = i / 100.f;
			float x2 = (i + 1) / 100.f;

			float y1 = parabolaflip(x1);
			float y2 = parabolaflip(x2);

			x1 *= 1200;
			x2 *= 1200;
			y1 *= 1200;
			y2 *= 1200;

			sfw::drawLine(x1, y1, x2, y2);


		}
		/*ang_vec += sfw::getDeltaTime();
		vec2 incident = fromAngle(ang_vec) * 40;
		float proj = dot(basis, incident);*/

		/*sfw::drawLine(400,300, 400+basis.x,300+basis.y,WHITE);
		sfw::drawLine(400, 300, 400 + incident.x, 300 + incident.y, WHITE);
		sfw::drawLine(400, 300, 400 + proj, 300 , WHITE);*/

		/*trans.debugDaw();*/
	}
	sfw::termContext();
}