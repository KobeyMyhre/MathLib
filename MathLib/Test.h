#pragma once


int doNothing(int x);

float test_quad(float x);

struct quad_results
{
	float left_root, right_root;
	int roots;
};

quad_results quad(float a, float b, float c);


float lerp(float start, float end, float t);

struct oint { float x, y; };
float distance(oint p1, oint p2);

struct hoint { float x, y, z; };
float inner(hoint p1, hoint q2);

struct Plane { float a, b, c, d; };
struct Xoint { float x, y, z; };
float Point(Plane plane, Xoint point);