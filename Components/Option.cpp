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
	sfw::drawString(d, "Press Enter to Start a New Game", 100, 100, 20, 20, 0, 0, WHITE);
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
