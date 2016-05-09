#pragma once

#include "Item.h"

class EnderpearlItem : public Item
{
public:
	EnderpearlItem(const std::string&, int);

	virtual ~EnderpearlItem();
	virtual bool use(ItemInstance&, Player&);
};
