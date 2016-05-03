#pragma once

#include "Item.h"
class ItemInstance;
class Level;
class Entity;

class ComplexItem : public Item {
public:
	ComplexItem(const std::string&, int);

	virtual ~ComplexItem();
	virtual bool isComplex() const;
	virtual void getUpdatePacket(ItemInstance&, Level&, Entity&);
};
