#pragma once

#include "BlockItem.h"

class AuxDataBlockItem : public BlockItem
{
public:
	AuxDataBlockItem(const std::string&, int, const Block*);

	virtual ~AuxDataBlockItem();
	virtual int getLevelDataForAuxValue(int) const;
	virtual std::string buildDescriptionName(const ItemInstance&) const;
};

