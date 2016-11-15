#include "objectCollision.h"

void playerObjectCollision(PlayerShip & player, ColliderObj &CO)
{
	StaticResolution(player.transform, player.rigidbody, player.collider, CO.transform, CO.collider, 1);
}

void ObjectCollision(ColliderObj & as1, ColliderObj & as2)
{
	if (&as1 == &as2)
		return;

	DynamicResolution(as1.transform, as1.rigidbody, as1.collider, as2.transform, as2.rigidbody, as2.collider);
}
