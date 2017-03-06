#pragma once

#include "../../inventory/FillingContainer.h"

class Block;
class Entity;

// Size : 40
class Inventory
{
public:
	Player *player;	// 36
	char filler[1000];
public:
	Inventory(Player *, bool);
	virtual ~Inventory();
	void add(ItemInstance&,bool);
	void clearSlot(int);
	void doDrop(ItemInstance *, bool);
	bool canDestroy(Block *);
	bool canAdd(ItemInstance const&)const;
	void clearInventoryWithDefault(bool);
	void getAttackDamage(Entity *);
	void getDestroySpeed(Block *);
	void getLinkedSlotForItem(int);
	void getLinkedSlotForItemIdAndAux(int, int);
	ItemInstance* getSelectedItem() const;
	void getSelectionSize();
	void moveToSelectedSlot(int);
	void moveToSelectionSlot(int, int);
	void selectSlot(int);
	void setupDefault();
	void tick();
};
