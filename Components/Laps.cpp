#include "Laps.h"
#include <iostream>
#include "sfwdraw.h"
void drawScore(unsigned font, int laps, float Time)
{

	char buffer[64] = {0};
	sprintf_s(buffer, "LAPS %d /3", laps);
	sfw::drawString(font, buffer, 600, 750, 20, 20);
	char buffer1[64] = { 0 };
	sprintf_s(buffer1, "TIME: %d", Time);
	sfw::drawString(font, buffer1, 600, 700, 20, 20);
}
