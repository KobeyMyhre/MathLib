#pragma once
#include "ColliderObject.h"
#include "PlayerShip.h"
#include "LapLine.h"
#include "PickUps.h"

void playerObjectCollision(PlayerShip &player, ColliderObj &CO, Track &T);
void playerLapCollision(PlayerShip & player, LapLine &LL, LapLine &L2, Track &T);
void ObjectCollision(ColliderObj &as1, ColliderObj &as2);
void playerPickUpCollision( PlayerShip &player, PickUps &CO, Track &T );
void playerPickUpCollision2(PlayerShip &player, PickUps &CO, Track &T);
void playerPickUpCollision3(PlayerShip &player, PickUps &CO, Track &T);
void playerPickUpCollision4(PlayerShip &player, PickUps &CO, Track &T);