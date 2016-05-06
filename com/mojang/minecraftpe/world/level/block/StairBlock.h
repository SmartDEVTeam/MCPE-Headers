#pragma once

#include "Block.h"

class StairBlock : public Block {
public:
	StairBlock(const std::string&, int, Block&, int);

	virtual ~StairBlock();
	virtual void tick(BlockSource&, const BlockPos&, Random&);
	virtual bool addAABBs(BlockSource&, const BlockPos&, const AABB*, std::vector<AABB, std::allocator<AABB>>&);
	virtual const AABB& getAABB(BlockSource&, const BlockPos&, const AABB&, int, bool, int);
	virtual void addCollisionShapes(BlockSource&, const BlockPos&, const AABB*, std::vector<AABB>&, Entity*);
	virtual void onPlace(BlockSource&, const BlockPos&);
	virtual void onRemove(BlockSource&, const BlockPos&);
	virtual void onExploded(BlockSource&, const BlockPos&, Entity*);
	virtual void onStepOn(Entity&, const BlockPos&);
	virtual bool mayPick();
	virtual bool mayPick(BlockSource&, int, bool);
	virtual bool mayPlace(BlockSource&, const BlockPos&, signed char);
	virtual void destroy(BlockSource&, const BlockPos&, int, Entity*);
	virtual int getResourceCount(Random&, int, int);
	virtual float getExplosionResistence(Entity*);
	virtual void clip(BlockSource&, const BlockPos&, const Vec3&, const Vec3&, bool, int);
	virtual bool use(Player&, const BlockPos&);
	virtual int getPlacementDataValue(Mob&, const BlockPos&, signed char, const Vec3&, int);
	virtual void attack(Player*, const BlockPos&);
	virtual void handleEntityInside(BlockSource&, const BlockPos&, Entity*, Vec3&);
	virtual const TextureUVCoordinateSet& getTexture(signed char);
	virtual const TextureUVCoordinateSet& getTexture(signed char, int);
	virtual const TextureUVCoordinateSet& getTexture(BlockSource&, const BlockPos&, signed char);
	virtual void prepareRender(BlockSource&, const BlockPos&);
	virtual bool animateTick(BlockSource&, const BlockPos&, Random&);
	virtual bool canBeSilkTouched() const;
};
