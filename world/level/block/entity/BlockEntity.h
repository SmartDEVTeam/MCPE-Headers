#pragma once

#include <string>
#include <vector>

#include "BlockEntityType.h"
class BlockSource;
class CompoundTag;
struct BlockPos;

class BlockEntity
{
public:
	BlockEntity(BlockEntityType, const BlockPos&, const std::string&);

	virtual ~BlockEntity();
	virtual void load(const CompoundTag&);
	virtual void save(CompoundTag&);
	virtual void tick(BlockSource&);
	virtual bool isFinished();
	virtual void onChanged(BlockSource&);
	virtual bool isMovable();
	virtual void getUpdatePacket(BlockSource&);
	virtual void onUpdatePacket(const CompoundTag&, BlockSource&);
	virtual void onMove();
	virtual void onRemoved(BlockSource&);
	virtual void triggerEvent(int, int);
	virtual void clearCache();
	virtual void onNeighborChanged(BlockSource&, const BlockPos&);
	virtual float getShadowRadius(BlockSource&) const;
	virtual bool hasAlphaLayer() const;
	virtual void getCrackEntity(BlockSource&, const BlockPos&);
	virtual std::string getDebugText(std::vector<std::string, std::allocator<std::string>>&);
};
