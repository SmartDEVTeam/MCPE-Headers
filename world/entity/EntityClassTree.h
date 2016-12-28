#pragma once

#include "Entity.h"
#include "EntityType.h"

class EntityClassTree
{
public:
	static bool isItemEntity(Entity const&);
	static bool isPlayer(Entity const&);
	static bool isMob(Entity const&);
	static bool isInstanceOf(Entity const&,EntityType);
};

