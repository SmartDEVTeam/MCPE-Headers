#pragma once
#include <memory>
#include "EntityType.h"
class Mob;
class BlockSource;
class Vec3;

class MobFactory 
{
public:
	static std::unique_ptr<Mob> CreateMob(EntityType, BlockSource&, const Vec3&);
	static std::string GetMobNameID(EntityType);
};
