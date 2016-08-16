#pragma once
#include "LiquidBlock.h"

class LiquidBlockDynamic : public LiquidBlock {
protected:
	int maxCount;
	bool result[4];
	int dist[4];

public:
	LiquidBlockDynamic(const std::string&, int, const Material&, const std::string&, const std::string&);

	virtual ~LiquidBlockDynamic();
	virtual void tick(BlockSource&, const BlockPos&, Random&);
	virtual void onPlace(BlockSource&, const BlockPos&);
};
