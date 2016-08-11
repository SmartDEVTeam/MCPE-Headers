#pragma once

#include "Item.h"

class BoatItem : public Item
{
public:
	BoatItem(const std::string&, int);

	virtual ~BoatItem();
	virtual bool isStakckedByData();
	virtual bool isLiquidClipItem(int);
	virtual bool useOn(ItemInstance*, Player*, int, int, int, signed char, float, float, float);
	virtual const std::string buildDescriptionName(const ItemInstance&) const;
	virtual bool getIcon(int, int, bool);
};
