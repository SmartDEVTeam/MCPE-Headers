#pragma once

#include "Item.h"

class HorseArmorItem : public Item
{
public:
	enum class HorseArmorTier : int {};

	static int mHealthPerTier[7];

	HorseArmorItem(const std::string&, int, int, const HorseArmorItem::HorseArmorTier&);

	virtual ~HorseArmorItem();
	virtual const std::string& appendFormattedHovertext(const ItemInstance&, const Player&, std::string&, bool) const;
	virtual int getColor(const ItemInstance&) const;
	virtual void dispense(BlockSource&, Container&, int, const Vec3&, signed char);

	void getTier();
	bool hasCustomColor(const ItemInstance&) const;
	void setColor(ItemInstance&, const Color&);
	void clearColor(ItemInstance&);
};
