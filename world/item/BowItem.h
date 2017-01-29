#pragma once

#include "Item.h"

class BowItem : public Item
{
public:
	TextureUVCoordinateSet& bow_pulling_0; // 108
	char filler1[24]; // 112
	TextureUVCoordinateSet& bow_pulling_1; // 136
	char filler2[24]; // 140
	TextureUVCoordinateSet& bow_pulling_2; // 164

	BowItem(const std::string&, int);

	virtual ~BowItem();
	virtual int getEnchantSlot() const;
	virtual int getEnchantValue() const;
	virtual bool use(ItemInstance&, Player&);
	virtual CameraItemComponent releaseUsing(ItemInstance*, Player*, int);
	virtual int getAnimationFrameFor(Mob&) const;
	virtual const TextureUVCoordinateSet& getIcon(int, int, bool) const;
};

