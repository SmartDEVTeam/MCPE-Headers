#pragma once

#include "Block.h"

class FireBlock : public Block
{
public:
	FireBlock(const std::string&, int);
	
	virtual ~FireBlock();
	virtual bool tick(BlockSource&, const BlockPos&, Random&) const;
	virtual AABB& getAABB(BlockSource&, const BlockPos&, AABB&, int, bool, int) const;
	virtual void onPlace(BlockSource&, const BlockPos&) const;
	virtual bool mayPick() const;
	virtual bool mayPlace(BlockSource&, const BlockPos&) const;
	virtual void neighborChanged(BlockSource&, const BlockPos&, const BlockPos&) const;
	virtual int getResourceCount(Random&, int, int) const;
	virtual bool animateTick(BlockSource&, const BlockPos&, Random&) const;
	virtual bool canBeSilkTouched() const;
	
	void setFlammable(BlockID, int, int);
};

