#pragma once

#include "BlockEntity.h"

class ItemInstance;
class Player;

class FurnaceBlockEntity : public BlockEntity
{
public:
	FurnaceBlockEntity(const BlockPos&);

	virtual ~FurnaceBlockEntity();
	virtual void load(const CompoundTag&);
	virtual void save(CompoundTag&);
	virtual void tick(BlockSource&);
	virtual bool isFinished();
	virtual void onMove();
	virtual void onNeighborChanged(BlockSource&, const BlockPos&);
	virtual ItemInstance* getItem(int) const;
	virtual void setItem(int, const ItemInstance*);
	virtual void removeItem(int, int);
	virtual std::string getName() const;
	virtual int getMaxStackSize() const;
	virtual int getContainerSize() const;
	virtual void startOpen(Player&);
	virtual void stopOpen(Player&);
	virtual void canPushInItem(BlockSource&, int, int, ItemInstance*);
	virtual void canPullOutItem(BlockSource&, int, int, ItemInstance*);

	bool isFuel(const ItemInstance*);
	void setLitTime(int);
	void setTickTime(int);
	int getLitProgress(int);
	void setLitDuration(int);
	int getBurnProgress(int);
	void getLastFuelSource();
	int getLitTime();
	int getTickCount();
	bool canBurn();
	int getBurnDuration(const ItemInstance*);
};
