#pragma once

#include "Item.h"

class BowItem : public Item
{
public:
	BowItem(const std::string&, int);

	virtual ~BowItem();
	virtual int getEnchantSlot() const;
	virtual int getEnchantValue() const;
	virtual bool use(ItemInstance&, Player&);
	virtual void releaseUsing(ItemInstance*, Player*, int);
	virtual int getAnimationFrameFor(Mob&) const;
	virtual const TextureUVCoordinateSet& getIcon(int, int, bool) const;

	void _getLaunchPower(int);
};
