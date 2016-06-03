#pragma once

class ContainerListener;
class ItemInstance;
class BlockSource;
class CompoundTag;

//These Are Wrong
class Vec3;
class Random;
class std::string;

class Container{
public:
	virtual ~Container();
	virtual void addListener(ContainerListener*);
	virtual void removeListener(ContainerListener*);
	virtual void addItem(ItemInstance*);
	virtual void addItemToFirstEmptySlot(ItemInstance*);
	virtual void getRandomEmptySlot(Random &);
	virtual void dropContents(BlockSource&,const Vec3&);
	virtual void getSlotCopies(void);
	virtual void getSlots(void);
	virtual void getItemCount(int);
	virtual void canPushInItem(int,int,ItemInstance*);
	virtual void canPullOutItem(int,int,ItemInstance*);
	virtual void setContainerChanged(int);
	virtual void setCustomName(const std::string&);
	virtual void hasCustomName(void);
	virtual void readAdditionalSaveData(const CompoundTag&);
	virtual void addAdditionalSaveData(CompoundTag&);
}