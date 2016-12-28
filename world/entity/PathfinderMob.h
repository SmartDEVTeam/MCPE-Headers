#pragma once

#include "Mob.h"

// Size : 3204
class PathfinderMob : public Mob
{
public:
	static float MAX_TURN;

public:
	char filler1[26]; // 3178

public:
	PathfinderMob(BlockSource &);
	virtual ~PathfinderMob(){};
	virtual void updateAi();
	virtual void getAttackTarget();
	virtual void setAttackTarget(Entity *);
};
