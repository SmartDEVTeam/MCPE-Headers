#pragma once

#include "Item.h"

class Material;
class DoorBlock { class DoorType; };

class DoorItem : public Item {
public:
	DoorItem(const std::string&, int, const Material&, DoorBlock::DoorType);
	
	virtual bool useOn(ItemInstance*, Player*, int, int, int, signed char, float, float, float);
	
	static void place(BlockSource*, int, int, int, int, Block*);
};