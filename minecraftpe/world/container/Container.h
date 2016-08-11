#pragma once

#include <string>

#include "ContainerType.h"
class ContainerListener;
class ItemInstance;
class BlockSource;
class CompoundTag;
class Vec3;
class Random;

class Container{
public:
	Container(ContainerType);
	Container(ContainerType, const std::string&, bool);
	
	virtual ~Container();
	virtual void addListener(ContainerListener*);
	virtual void removeListener(ContainerListener*);
	virtual void addItem(ItemInstance*);
	virtual void addItemToFirstEmptySlot(ItemInstance*);
	virtual void getRandomEmptySlot(Random&);
	virtual void dropContents(BlockSource&, const Vec3&);
	virtual void getSlotCopies() const;
	virtual int getSlots();
	virtual void getItemCount(int);
	virtual void canPushInItem(int, int, ItemInstance*);
	virtual void canPullOutItem(int, int, ItemInstance*);
	virtual void setContainerChanged(int);
	virtual void setCustomName(const std::string&);
	virtual bool hasCustomName() const;
	virtual void readAdditionalSaveData(CompoundTag const&);
	virtual void addAdditionalSaveData(CompoundTag &);
}