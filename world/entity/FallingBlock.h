#pragma once

#include "Entity.h"

class FallingBlock : public Entity
{
public:
	char filler[200];
	FallingBlock(BlockSource&,Vec3 const&,FullBlock,bool);
	virtual ~FallingBlock();
	virtual EntityType getEntityTypeId()const;
	virtual void readAdditionalSaveData(const CompoundTag*);
	virtual void addAdditionalSaveData(CompoundTag*);
	void normalTick();
};
