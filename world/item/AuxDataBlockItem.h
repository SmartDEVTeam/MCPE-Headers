#pragma once
#include "BlockItem.h"

class Block;

class AuxDataBlockItem : public BlockItem {
	Block* blockPtr;

public:
	AuxDataBlockItem(const std::string&, int, Block const*);

	virtual ~AuxDataBlockItem();
	virtual int getLevelDataForAuxValue(int) const;
	virtual const std::string buildDescriptionName(const ItemInstance&) const;
};
