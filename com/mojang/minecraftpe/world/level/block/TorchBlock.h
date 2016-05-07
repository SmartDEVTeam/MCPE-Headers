#pragma once

#include "Block.h"

class TorchBlock : public Block {
public:
	TorchBlock();

	virtual ~TorchBlock();
	virtual void tick(BlockSource&, const BlockPos&, Random&);
	virtual const AABB& getAABB(BlockSource&, const BlockPos&, AABB&, int, bool, int);
	virtual void onPlace(BlockSource&, const BlockPos&);
	virtual void onRemove(BlockSource&, const BlockPos&);
	virtual bool mayPlace(BlockSource&, const BlockPos&, signed char);
	virtual bool mayPlace(BlockSource&, const BlockPos&);
	virtual void neighborChanged(BlockSource&, const BlockPos&, const BlockPos&);
	virtual int getPlacementDataValue(Mob&, const BlockPos&, signed char, const Vec3&, int);
	virtual int getIconYOffset() const;
	virtual const AABB& getVisualShape(BlockSource&, const BlockPos&, AABB&, bool);
	virtual bool animateTick(BlockSource&, const BlockPos&, Random&);
	virtual bool canBeSilkTouched() const;
};
