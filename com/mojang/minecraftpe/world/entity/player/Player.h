#pragma once
#include "../Entity.h"
#include "../../item/ItemInstance.h"

class Player : public Entity {
public:
	char filler2[2971];
	bool creativeMode;

	void drop(const ItemInstance*);
	ItemInstance* getSelectedItem() const;
};
