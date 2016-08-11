#pragma once

#include "Block.h"

class ChestBlock : public Block {
public:
	enum class ChestType : int {
		NORMAL_CHEST,
		TRAP_CHEST
	};

	ChestBlock(const std::string&, int, ChestBlock::ChestType);

	virtual void tick(BlockSource&, const BlockPos&, Random&);
	virtual bool isContainerBlock() const;
	virtual bool isRedstoneBlock() const;
	virtual void onPlace(BlockSource&, const BlockPos&);
	virtual void onRemove(BlockSource&, const BlockPos&);
	virtual void onLoaded(BlockSource&, const BlockPos&);
	virtual void getSecondPart(BlockSource&, const BlockPos&, const BlockPos&);
	virtual bool use(Player&, const BlockPos&);
	virtual int getPlacementDataValue(Mob&, const BlockPos&, signed char, const Vec3&, int);
	virtual bool hasComparatorSignal();
	virtual int getComparatorSignal(BlockSource&, const BlockPos&, signed char, int);
	virtual const TextureUVCoordinateSet& getTexture(signed char);
	virtual const TextureUVCoordinateSet& getTexture(BlockSource&, const BlockPos&, signed char);
	virtual void init();
	virtual bool canBeSilkTouched() const;
};
