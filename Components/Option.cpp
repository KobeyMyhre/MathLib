#include "Option.h"
#include "sfwdraw.h"
#include <iostream>
void option::init(int a_font)
{
	d = a_font;
}

void option::play()
{
	 timer = 3.f;
}

void option::draw()
{
	sfw::drawString(d, "Please Enter Credit Card Information To Continue", 50, 500, 15, 15, 0, 0, GREEN);
	sfw::drawString(d, "XXXX-XXXX-XXXX-XXXX", 100, 475, 20, 20, 0, 0, BLACK);
	sfw::drawString(d, "[ENTER]", 400, 200, 20, 20, 0, 0, GREEN);
	//sfw::drawString(d, "Press I to View Controlls", 100, 300, 20, 20, 0, 0, WHITE);
}

void option::step()
{
}

MenuState option::next()
{
	if (sfw::getKey(KEY_ENTER))
	{
		return Enter_Game;
	}

	return Option;
}
