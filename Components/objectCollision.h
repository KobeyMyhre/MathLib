#pragma once
#include "ColliderObject.h"
#include "PlayerShip.h"
#include "LapLine.h"

void playerObjectCollision(PlayerShip &player, ColliderObj &CO);
void playerLapCollision(PlayerShip & player, LapLine &LL);
void ObjectCollision(ColliderObj &as1, ColliderObj &as2);
