#include "MenuState.h"
class depart
{
public:
	int d;
	int s;
	float timer;
	int select;

	void init(int a_font);
	void play(int a_succes);
	void draw();
	void step();

	MenuState next();
};