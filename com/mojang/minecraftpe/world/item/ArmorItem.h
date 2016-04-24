#pragma once

#include "Item.h"
#include "ItemInstance.h"

class Color;

enum class ArmorSlot : int {
	HELMET,
	CHESTPLATE,
	LEGGINGS,
	BOOTS
};

// Size : 88
class ArmorItem : public Item {
public:
	// Size : 20
	class ArmorMaterial {
	public:
		int i1;		// 0
		int defense;// 4
		int i3;		// 8
		int i4;		// 12
		int i5;		// 16
		int i6;		// 20

	public:
		ArmorMaterial(int, int, int, int, int, int);
		int getDefenseForSlot(int);
		int getEnchantValue();
		int getHealthForSlot(int);
	};

public:
	static ArmorMaterial CHAIN;
	static ArmorMaterial CLOTH;
	static ArmorMaterial DIAMOND;
	static ArmorMaterial GOLD;
	static ArmorMaterial IRON;
	static int mHealthPerSlot[10];

public:
	ArmorSlot armorType;			// 68
	int defence;					// 72
	int renderIndex;				// 76
	ArmorMaterial& armorMaterial;	// 80

public:
	ArmorItem(const std::string&, int, const ArmorItem::ArmorMaterial &, int, ArmorSlot);
	virtual ~ArmorItem();
	virtual bool isArmor() const;
	virtual const std::string& appendFormattedHovertext(const ItemInstance&, const Player&, std::string&, bool) const;
	virtual bool isValidRepairItem(const ItemInstance&, const ItemInstance&);
	virtual int getEnchantSlot() const; 
	virtual int getEnchantValue() const;
    virtual int getColor(const ItemInstance&) const;
    virtual void dispense(BlockSource&, Container&, int, const Vec3&, signed char);
	ItemInstance getTierItem();
	void setColor(ItemInstance&, const Color&);
	void clearColor(ItemInstance&);
	int getSlotForItem(const ItemInstance&);
	static Item* getArmorForSlot(ArmorSlot, int);
};
