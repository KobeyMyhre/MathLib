#pragma once
#include "MenuState.h"
class option
{
public:
	int d;
	float timer;
	int select;

	void init(int a_font);
	void play();
	void draw();
	void step();

	MenuState next();
};