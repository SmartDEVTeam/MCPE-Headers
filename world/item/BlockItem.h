#pragma once

#include "Item.h"

class BlockItem : public Item
{
public:
	BlockItem(const std::string&, int);

	virtual ~BlockItem();
	virtual bool isDestructive(int) const;
	virtual bool isValidAuxValue(int) const;
	virtual std::string buildDescriptionName(const ItemInstance&) const;
	virtual bool isEmissive(int) const;
	virtual const TextureUVCoordinateSet& getIcon(int, int, bool) const;
	virtual int getIconYOffset() const;
	virtual void _calculatePlacePos(ItemInstance&, Entity&, signed char&, BlockPos&) const;
	virtual bool _useOn(ItemInstance&, Entity&, BlockPos, signed char, float, float, float) const;
};
