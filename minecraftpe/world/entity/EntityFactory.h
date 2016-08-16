#pragma once
#include <memory>
#include "EntityType.h"
class Entity;
class BlockSource;

struct EntityFactory {
	static std::unique_ptr<Entity> CreateEntity(EntityType, BlockSource&);
};

