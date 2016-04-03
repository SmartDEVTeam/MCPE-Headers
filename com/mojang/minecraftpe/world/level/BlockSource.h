#pragma once
class Block;
struct BlockPos;
class Material;
class BlockEntity;
class Level;
#include "../../CommonTypes.h"

class BlockSource {
public:
	Level* getLevel() const;
	Block* getBlock(const BlockPos&);
	FullBlock getBlockID(const BlockPos&);
	DataID getData(const BlockPos&);
	Material& getMaterial(const BlockPos&);
	bool setBlockAndData(const BlockPos&, FullBlock, int);
	bool setBlock(const BlockPos&, BlockID, int);
	bool setExtraData(const BlockPos&, unsigned short);
	void removeBlock(const BlockPos&);
	BlockEntity* getBlockEntity(const BlockPos&);
	int getTopSolidBlock(const BlockPos&, bool);
	int getTopSolidBlock(int, int, bool);
};
