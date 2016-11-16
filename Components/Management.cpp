#include "Management.h"
#include "sfwdraw.h"
void Management::Timer(float & time)
{
	time = 30.f;

	time -= sfw::getDeltaTime;

}
