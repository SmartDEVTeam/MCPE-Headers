#pragma once

#include "Block.h"

class DoorBlock : public Block
{
public:
	enum class DoorType : int {};

	DoorBlock(const std::string&, int, const Material&, DoorType);

	virtual ~DoorBlock();
	virtual ItemInstance& asItemInstance(BlockSource&, const BlockPos&, int) const;
	virtual bool canBeSilkTouched() const;
	virtual bool checkIsPathable(Entity&, const BlockPos&, const BlockPos&);
	virtual void getCompositeData(BlockSource&, const BlockPos&);
	virtual int getResource(Random&, int, int);
	virtual void getSecondPart(BlockSource&, const BlockPos&, BlockPos&);
	virtual ItemInstance& getSilkTouchItemInstance(unsigned char);
	virtual void getTessellatedUVs();
	virtual const TextureUVCoordinateSet& getTexture(BlockSource&, const BlockPos&, signed char);
	virtual const TextureUVCoordinateSet& getTexture(signed char, int);
	virtual const AABB& getVisualShape(BlockSource&, const BlockPos&, AABB&, bool);
	virtual bool hasRightHinge(unsigned char);
	virtual bool isDoorBlock() const;
	virtual bool isInteractiveBlock() const;
	virtual bool isWaterBlocking() const;
	virtual bool mayPlace(BlockSource&, const BlockPos&);
	virtual void neighborChanged(BlockSource&, const BlockPos&, const BlockPos&);
	virtual void onLoaded(BlockSource&, const BlockPos&);
	virtual void onPlace(BlockSource&, const BlockPos&);
	virtual void onRedstoneUpdate(BlockSource&, const BlockPos&, int, bool);
	virtual void shouldFlipTexture(int, signed char);
	virtual void tick(BlockSource&, const BlockPos&, Random &);
	virtual bool use(Player&, const BlockPos&);

	bool isOpen(int);
	bool isOpen(BlockSource&, const BlockPos&);
	bool isUpper(unsigned char);
	void setOpen(BlockSource&, const BlockPos&, bool, Mob*);
	void getDir(BlockSource&, const BlockPos&);
};
