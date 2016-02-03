#pragma once
#include "LiquidBlock.h"

class LiquidBlockStatic : public LiquidBlock {
protected:
	BlockID _dynamic;

public:
	LiquidBlockStatic(const std::string&, int, BlockID, const Material&, const std::string&, const std::string&);

	virtual ~LiquidBlockStatic();
	virtual void tick(BlockSource&, const BlockPos&, Random&);
	virtual void neighborChanged(BlockSource&, const BlockPos&, const BlockPos&);
};
