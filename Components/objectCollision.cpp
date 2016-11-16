#include "objectCollision.h"
#include "LapLine.h"
void playerObjectCollision(PlayerShip & player, ColliderObj &CO, Track &T)
{
	//StaticResolution(player.transform, player.rigidbody, player.collider, CO.transform, CO.collider, 1);
	StaticResolutionWithTime(T,player.transform, player.rigidbody, player.collider, CO.transform, CO.collider, 1);
}
void playerLapCollision(PlayerShip & player, LapLine &LL, LapLine &L2, Track &T)
{
	LapResolution(T, player.transform, player.rigidbody, player.collider, LL.transform, LL.collider, L2.transform, L2.collider);
}

void ObjectCollision(ColliderObj & as1, ColliderObj & as2)
{
	if (&as1 == &as2)
		return;

	DynamicResolution(as1.transform, as1.rigidbody, as1.collider, as2.transform, as2.rigidbody, as2.collider);
}
