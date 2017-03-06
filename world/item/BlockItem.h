#pragma once

#include "Item.h"

class BlockItem : public Item {
public:
	BlockItem(const std::string&, int);

	virtual ~BlockItem();
	virtual bool useOn(ItemInstance*, Player*, int, int, int, signed char, float, float, float);
	virtual const std::string buildDescriptionName(const ItemInstance&) const;
	virtual bool isEmissive(int) const;
	virtual const TextureUVCoordinateSet& getIcon(int, int, bool) const;
	virtual int getIconYOffset() const;
};
