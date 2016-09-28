#include "sfwdraw.h"
#include "vec2.h"
#include "Transform.h"
#include "flops.h"
void main()
{
	sfw::initContext();
	//Transform trans;
	Transform trans(400, 300, 12, 12, 0);

	Transform T = Transform();
	/*trans.position = vec2{ 400,300 };*/
	int i = int();
	int j = int(4);
	int k(4);
	int l = { 4 };
	int m = 4;

	Transform tl = Transform(400, 300);
	Transform tn = { 400, 300 };
	Transform tm(400, 300);
	Transform tq{ 400,300 };


	trans.facing = deg2rad(45);
	trans.scale = vec2{ 35,15 };
	vec2 basis = { 40,0 };
	float ang_vec = 0;

	while (sfw::stepContext())
	{
		ang_vec += sfw::getDeltaTime();
		vec2 incident = fromAngle(ang_vec) * 40;
		float proj = dot(basis, incident);

		sfw::drawLine();


		trans.debugDaw();
	}
	sfw::termContext();
}