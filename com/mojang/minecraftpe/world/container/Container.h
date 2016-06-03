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
	virtual void Container::addListener(ContainerListener *);
	virtual void Container::removeListener(ContainerListener *);
	virtual void Container::addItem(ItemInstance *);
	virtual void Container::addItemToFirstEmptySlot(ItemInstance *);
	virtual void Container::getRandomEmptySlot(Random &);
	virtual void Container::dropContents(BlockSource &,Vec3 const&);
	virtual void Container::getSlotCopies(void);
	virtual void Container::getSlots(void);
	virtual void Container::getItemCount(int);
	virtual void Container::canPushInItem(int,int,ItemInstance *);
	virtual void Container::canPullOutItem(int,int,ItemInstance *);
	virtual void Container::setContainerChanged(int);
	virtual void Container::setCustomName(std::string const&);
	virtual void Container::hasCustomName(void);
	virtual void Container::readAdditionalSaveData(CompoundTag const&);
	virtual void Container::addAdditionalSaveData(CompoundTag &);
}