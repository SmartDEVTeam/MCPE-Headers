#pragma once

#include <memory>

class BlockSource;
struct BlockPos;
struct FullBlock;
class BlockEntity;
class Entity;

class BlockSourceListener
{
	virtual ~BlockSourceListener();
	virtual void onSourceCreated(BlockSource&);
	virtual void onSourceDestroyed(BlockSource&);
	virtual void onBlocksDirty(BlockSource&, const BlockPos&, const BlockPos&);
	virtual void onAreaChanged(BlockSource&, const BlockPos&, const BlockPos&);
	virtual void onBlockChanged(BlockSource&, const BlockPos&, FullBlock, FullBlock, int, Entity*);
	virtual void onBrightnessChanged(BlockSource&, const BlockPos&);
	virtual void onBlockEntityChanged(BlockSource&, BlockEntity&);
	virtual void onEntityChanged(BlockSource&, Entity&);
	virtual void onBlockEntityRemoved(BlockSource&, std::unique_ptr<BlockEntity, std::default_delete<BlockEntity>>);
	virtual void onBlockEvent(BlockSource&, int, int, int, int, int);
};
