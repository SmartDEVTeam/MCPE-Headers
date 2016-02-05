#pragma once
#include <memory>
#include "EntityType.h"
class Mob;
class BlockSource;
class Vec3;

struct MobFactory {
	static std::unique_ptr<Mob> CreateMob(EntityType, BlockSource&, const Vec3&);
};

