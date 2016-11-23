#include "shapes.h"
#include "mat3.h"]
#include "math.h"
#include "Collision.h"
circle operator*(const mat3 & T, const circle & C)
{
	circle retval;

	retval.pos = (T * vec3{ C.pos.x, C.pos.y, 1 }).xy;
	
	float yRad = magnitude(T * vec3{C.radius , 0, 0});
	float xRad = magnitude(T * vec3{0,C.radius,0});

	retval.radius = xRad > yRad ? xRad : yRad;

	return retval;
}

bool operator==(const circle &A, const circle &B)
{
	return A.pos == B.pos && fequals(A.radius, B.radius);
}

AABB operator*(const mat3 & T, const AABB & B)
{
	AABB retval = B;

	/*retval.pos = (T * vec3{ B.pos.x, B.pos.y, 1 }).xy;*/





	vec3 ta = (T * vec3{ B.min().x, B.min().y, 1 });
	vec3 tb = (T * vec3{ B.min().x, B.max().y, 1 });
	vec3 tc = (T * vec3{ B.max().x, B.min().y, 1 });
	vec3 td = (T * vec3{ B.max().x, B.max().y, 1 });

	float posx = (ta.x + tb.x + tc.x + td.x) / 4;
	float posy = (ta.y + tb.y + tc.y + td.y) / 4;
	retval.pos = ( vec3{ posx,posy, 1 }).xy;


	float greatestX;
	float smallestX;
	float greatestY;
	float smallestY;

	

	if (ta.x <= tb.x && ta.x <= tc.x && ta.x <= td.x)
	{
		smallestX = ta.x;
	}
	else if (tb.x <= ta.x && tb.x <= tc.x  && tb.x <= td.x)
	{
		smallestX = tb.x;
	}
	else if (tc.x <= ta.x && tc.x <= tb.x  && tc.x <= td.x)
	{
		smallestX = tc.x;
	}
	else
	{
		smallestX = td.x;
	}

	if (ta.y <= tb.y  && ta.y <= tc.y  && ta.y <= td.y)
	{
		smallestY = ta.y;
	}
	else if (tb.y <= ta.y  && tb.y <= tc.y  && tb.y <= td.y)
	{
		smallestY = tb.y;
	}
	else if (tc.y <= ta.y  && tc.y <= tb.y  && tc.y <= td.y)
	{
		smallestY = tc.y;
	}
	else
	{
		smallestY = td.y;
	}


	if (ta.x >= tb.x && ta.x >= tc.x && ta.x >= td.x)
	{
	greatestX = ta.x ;
	}
	else if (tb.x >= ta.x && tb.x >= tc.x && tb.x >= td.x)
	{
	greatestX = tb.x ;
	}
	else if (tc.x >= ta.x && tc.x >= tb.x && tc.x >= td.x)
	{
	greatestX = tc.x;
	}
	else
	{
	greatestX = td.x;
	}

	

	if (ta.y >= tb.y && ta.y >= tc.y && ta.y >= td.y)
	{
	greatestY = ta.y;
	}
	else if (tb.y >= ta.y && tb.y >= tc.y && tb.y >= td.y)
	{
	greatestY = tb.y;
	}
	else if (tc.y >= ta.y && tc.y >= tb.y && tc.y >= td.y)
	{
	greatestY = tc.y;
	}
	else
	{
	greatestY = td.y;
	}



	float halfX = (greatestX - smallestX) ;
	float halfY = (greatestY - smallestY) ;
	retval.he = { halfX,  halfY };
	

	/*float xhe1 = (ta.x - tc.x) /2;
	float yhe1 = (td.y - tb.y) /2;	

	retval.he = { ((posx - xhe1) / 6) ,  ((posy - yhe1) / 6) };*/



	
	return retval;

	
}

bool operator==(const AABB & A, const AABB & B)
{
	return false;
}







vec2 AABB::min() const
{
	return pos - he;
}

vec2 AABB::max() const
{
	return pos + he;
}
plane operator*(const mat3 & T, const plane & P)
{
	plane retval;
	retval.pos = (T * vec3{ P.pos.x, P.pos.y, 1 }).xy;
	retval.dir = normal(T * vec3{ P.dir.x,P.dir.y, 0 }).xy;
	return retval;
}

bool operator==(const plane & A, const plane & B)
{
	return A.pos == B.pos && A.dir == B.dir;
}


hull operator*(const mat3 & T, const hull & C)
{
	hull retval ;



	retval.size = C.size;
	for (int i = 0; i < C.size; i++)
	{
		retval.normals[i]  = normal((T * vec3 { C.normals[i].x  ,C.normals[i].y  , 0 }).xy);
		retval.vertices[i] = (T * vec3{ C.vertices[i].x  ,C.vertices[i].y , 1 }).xy;
		// fuck parrots 
		// you fucking poo poo brain idiot
		// magic the gathering sucks dick
	}

	return retval;
}

bool operator==(const hull & A, const hull & B)
{
	return A.vertices == B.vertices && A.normals == B.normals;
}

hull::hull(const vec2 * a_vertices, unsigned vsize)
{
	
	
	size = vsize;
	for (int i = 0; i < vsize && i < 16 ; i++)
	{
		vertices[i] = a_vertices[i];
		vec2 ToPerp = a_vertices[i] - a_vertices[(i + 1) % size];

		/*if (i >= vsize - 1)
		{
			 ToPerp = (a_vertices[i] - a_vertices[0]);
		}*/
		vec2 AbsToPerp = normal(ToPerp);    /*{ abs(ToPerp.x), abs(ToPerp.y) };*/
		vec2 finalPerp = perp(AbsToPerp);
		normals[i] = finalPerp;		
	}
	
	
}

hull::hull()
{

}
