#include "TrackManager.h"
#include "Transform.h"
#include "sfwdraw.h"


void Track::debugDrawGo(const mat3 & camera)

{

	//sfw::drawCircle(Go.m_position.x, Go.m_position.x, 6, 4, Go.m_color);
	
	Go.debugDrawGoX(camera);
}
