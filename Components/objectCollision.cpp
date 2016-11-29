#include "objectCollision.h"
#include "LapLine.h"
#include "PickUps.h"
void playerObjectCollision(PlayerShip & player, ColliderObj &CO, Track &T)
{
	//StaticResolution(player.transform, player.rigidbody, player.collider, CO.transform, CO.collider, 1);
	StaticResolutionWithEffect(T,player.transform, player.rigidbody, player.collider, CO.transform, CO.collider, 1);
}
void playerLapCollision(PlayerShip & player, LapLine &LL, LapLine &L2, Track &T)
{
	LapResolution(T, player.transform, player.rigidbody, player.collider, LL.transform, LL.collider, L2.transform, L2.collider);
}

void playerBoostCollision(PlayerShip & player, SpeedBoost & LL)
{

	StaticResolutionBoosts( player.transform, player.rigidbody, player.collider, LL.transform, LL.collider, 1);
}



void FunGateCollision(PlayerShip & player, LapLine & LL, LapLine & L2, Track & T)
{
	FunGateResolution(T, player.transform, player.spaceshiplocomotion, player.collider, LL.transform, LL.collider, L2.transform, L2.collider);
	
}

void ObjectCollision(ColliderObj & as1, ColliderObj & as2)
{
	if (&as1 == &as2)
		return;

	DynamicResolution(as1.transform, as1.rigidbody, as1.collider, as2.transform, as2.rigidbody, as2.collider);
}

void playerPickUpCollision(PlayerShip & player, PickUps & CO, Track & T)
{
	StaticResolutionForPickUps( T , player.transform, player.spaceshiplocomotion, player.collider, CO.transform, CO.collider, 1);
}
void playerPickUpCollision2(PlayerShip & player, PickUps & CO, Track & T)
{
	StaticResolutionForPickUps2(T, player.transform, player.spaceshiplocomotion, player.collider, CO.transform, CO.collider, 1);
}
void playerPickUpCollision3(PlayerShip & player, PickUps & CO, Track & T)
{
	StaticResolutionForPickUps3(T, player.transform, player.spaceshiplocomotion, player.collider, CO.transform, CO.collider, 1);
}
void playerPickUpCollision4(PlayerShip & player, PickUps & CO, Track & T)
{
	StaticResolutionForPickUps4(T, player.transform, player.spaceshiplocomotion, player.collider, CO.transform, CO.collider, 1);
}
