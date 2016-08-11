#pragma once

#include "Block.h"

class SlabBlock : public Block {
public:
	SlabBlock(const std::string&, int, const std::string&, bool, const Material&);

	virtual ~SlabBlock();
	virtual bool canBeSilkTouched() const;
	virtual bool checkIsPathable(Entity&, const BlockPos&, const BlockPos&);
	virtual int getPlacementDataValue(Mob&, const BlockPos&, signed char, const Vec3&, int);
	virtual void getRedstoneProperty(BlockSource&, const BlockPos&);
	virtual int getResourceCount(Random&, int, int);
	virtual const AABB& getVisualShape(unsigned char, AABB&, bool);
	virtual bool isObstructingChests(BlockSource&, const BlockPos&);
	virtual bool shouldRenderFace(BlockSource&, const BlockPos&, signed char, const AABB&) const;
	
	bool isBottomSlab(BlockSource&, const BlockPos&) const;
	bool isBottomSlab(int);
};
