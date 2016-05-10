#pragma once

#include "Block.h"

class ButtonBlock : public Block {
public:
	ButtonBlock(const std::string&, int, const std::string&, bool);

	virtual ~ButtonBlock();
	virtual void tick(BlockSource&, const BlockPos&, Random&);
	virtual const AABB& getCollisionShape(AABB&, BlockSource&, const BlockPos&, Entity*);
	virtual bool isInteractiveBlock() const;
	virtual bool isRedstoneBlock() const;
	virtual void onPlace(BlockSource&, const BlockPos&);
	virtual void onRedstoneUpdate(BlockSource&, const BlockPos&, int, bool);
	virtual void onLoaded(BlockSource&, const BlockPos&);
	virtual bool mayPlace(BlockSource&, const BlockPos&, signed char);
	virtual bool mayPlace(BlockSource&, const BlockPos&);
	virtual void neighborChanged(BlockSource&, const BlockPos&, const BlockPos&);
	virtual int getResource(Random&, int, int);
	virtual int getResourceCount(Random&, int, int);
	virtual ItemInstance& asItemInstance(BlockSource&, const BlockPos&, int) const;
	virtual bool use(Player&, const BlockPos&);
	virtual int getPlacementDataValue(Mob&, const BlockPos&, signed char, const Vec3&, int);
	virtual bool entityInside(BlockSource&, const BlockPos&, Entity&);
	virtual const AABB& getVisualShape(unsigned char, AABB&, bool);
	virtual int getSpawnResourcesAuxValue(unsigned char);
	virtual void blocksLight();
};
