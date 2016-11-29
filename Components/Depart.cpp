#include "departz.h"
#include "Management.h"
#include "sfwdraw.h"
#include <iostream>

void depart::init(int a_font)
{
	d = a_font;
}

void depart::play(int a_succes)
{
	timer = 5.f;
	s = a_succes;
}

void depart::draw()
{
	char buffer[64];
	
	/*sprintf_s(buffer, "Play Again?");
	sfw::drawString(d, buffer, 100, 100, 20, 20);*/

	
	if (s == 1)
	{
		sprintf_s(buffer, "You Win");
		sfw::drawString(d, buffer, 100, 100, 20, 20);
		
	}
	else
	{
		sprintf_s(buffer, "You Suck, Go Faster");
		sfw::drawString(d, buffer, 100, 100, 20, 20);
	}
	


	sfw::drawLine(100, 80, 100 + 500 * (timer / 4.f), 80);
	if (timer <= 2)
		sfw::drawString(d, "Insert 50 Credits to continue.", 100, 300, 20, 20);
}

void depart::step()
{
	timer -= sfw::getDeltaTime();
}

MenuState depart::next()
{
	if (timer < 0)
		return Enter_Option;

	return Depart;
}
