#pragma once

#include "Item.h"

class PotionItem : public Item
{
public:
	PotionItem(const std::string&, int);

	virtual bool isFoil(const ItemInstance&) const;
	virtual const std::string& appendFormattedHovertext(const ItemInstance&, const Player&, std::string&, bool) const;
	virtual bool use(ItemInstance&, Player&);
	virtual void useTimeDepleted(ItemInstance*, Level*, Player*);
	virtual const std::string buildDescriptionName(const ItemInstance&) const;
	virtual const std::string buildEffectDescriptionName(const ItemInstance&) const;
	virtual const TextureUVCoordinateSet& getIcon(int, int, bool) const;
	
	int getEffectId(const ItemInstance*);
};
