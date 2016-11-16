#pragma once
#include "ColliderObject.h"
#include "PlayerShip.h"
#include "LapLine.h"

void playerObjectCollision(PlayerShip &player, ColliderObj &CO, Track &T);
void playerLapCollision(PlayerShip & player, LapLine &LL, LapLine &L2, Track &T);
void ObjectCollision(ColliderObj &as1, ColliderObj &as2);
