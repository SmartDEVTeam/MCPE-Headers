#pragma once

class Block;
struct BlockPos;
class Material;
class BlockEntity;
class Level;
#include "FullBlock.h"

class BlockSource {
public:
	bool isConsideredSolidBlock(int, int, int);
	bool isConsideredSolidBlock(const BlockPos&);
	bool isEmptyBlock(int, int, int);
	bool isEmptyBlock(const BlockPos&);
	bool isHumidAt(const BlockPos&);
	bool isSnowTemperature(const BlockPos&);
	bool isSolidBlockingBlock(int, int, int);
	bool isSolidBlockingBlock(const BlockPos&);
	bool isTopSolidBlocking(Block*, unsigned char);
	bool isTopSolidBlocking(int, int, int);
	bool isTopSolidBlocking(const BlockPos&);
	Level* getLevel() const;
	Block* getBlock(int, int, int);
	Block* getBlock(const BlockPos&);
	int getBlockID(int, int, int);
	int getBlockID(const BlockPos&);
	int getData(int, int, int);
	int getData(const BlockPos&);
	Material& getMaterial(int, int, int);
	Material& getMaterial(const BlockPos&);
	bool setBlockAndData(int, int, int, BlockID, unsigned char, int);
	bool setBlockAndData(const BlockPos&, BlockID, unsigned char, int);
	bool setBlockAndData(int, int, int, FullBlock, int);
	bool setBlockAndData(const BlockPos&, FullBlock, int);
	bool setBlockAndDataNoUpdate(int, int, int, FullBlock);
	bool setBlock(int, int, int, BlockID, int);
	bool setBlock(const BlockPos&, BlockID, int);
	bool setBlockNoUpdate(int, int, int, BlockID);
	bool setExtraData(const BlockPos&, unsigned short);
	void removeBlock(int, int, int);
	void removeBlock(const BlockPos&);
	BlockEntity* getBlockEntity(const BlockPos&);
	int getTopSolidBlock(const BlockPos&, bool);
	int getTopSolidBlock(int, int, bool);
};

