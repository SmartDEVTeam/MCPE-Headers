#pragma once

#include "Item.h"
#include "ArmorSlot.h"

class ItemInstance;
class Color;

// Size : 124
class ArmorItem : public Item
{
public:
	// Size : 20
	class ArmorMaterial
	{
	public:
		int id; // 0
		int i2; // 4
		int i3; // 8
		int i4; // 12
		int i5; // 16
		int enchantValue; // 20

		ArmorMaterial(int, int, int, int, int, int);
		int getDefenseForSlot(int);
		int getEnchantValue();
		int getHealthForSlot(int);
	};

	static ArmorMaterial GOLD;
	static ArmorMaterial IRON;
	static ArmorMaterial CHAIN;
	static ArmorMaterial CLOTH;
	static ArmorMaterial ELYTRA;
	static ArmorMaterial DIAMOND;
	static int mHealthPerSlot[10];

	ArmorSlot armorSlot; // 112
	int renderIndex; // 116
	ArmorMaterial& armorMaterial; // 120
	int enchantValue; // 124

	ArmorItem(const std::string&, int, const ArmorItem::ArmorMaterial&, int, ArmorSlot);
	
	//virtual ~ArmorItem();
	virtual bool isArmor() const;
	virtual std::string appendFormattedHovertext(const ItemInstance&, Level&, std::string&, bool) const;
	virtual bool isValidRepairItem(const ItemInstance&, const ItemInstance&) const;
	virtual int getEnchantSlot() const;
	virtual int getEnchantValue() const;
	virtual int getDamageChance(int) const;
	virtual Color getColor(const ItemInstance&) const;
	virtual bool isTintable() const;
	virtual bool use(ItemInstance&, Player&) const;
	virtual void dispense(BlockSource&, Container&, int, const Vec3&, signed char) const;
	virtual void hurtEnemy(ItemInstance&, Mob*, Mob*) const;
	virtual bool mineBlock(ItemInstance&, BlockID, int, int, int, Entity*) const;
	virtual const TextureUVCoordinateSet& getIcon(int, int, bool) const;
	
	ItemInstance getTierItem() const;
	bool hasCustomColor(const ItemInstance&) const;
	void setColor(ItemInstance&, const Color&);
	void clearColor(ItemInstance&);
	int getSlotForItem(const ItemInstance&);
	Item* getArmorForSlot(ArmorSlot, int);
	bool isFlyEnabled(const ItemInstance&);
};
