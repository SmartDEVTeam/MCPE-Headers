#pragma once

#include "Item.h"

class SkullItem : public Item
{
public:
	SkullItem(const std::string&, int);

	virtual ~SkullItem();
	virtual int getLevelDataForAuxValue(int) const;
	virtual bool useOn(ItemInstance*, Player*, int, int, int, signed char, float, float, float);
	virtual const std::string buildDescriptionName(const ItemInstance&) const;
	virtual const TextureUVCoordinateSet& getIcon(int, int, bool) const;
};
