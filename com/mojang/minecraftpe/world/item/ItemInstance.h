#pragma once

#include <memory>
#include <string>

class Item;
class CompoundTag;
class Block;
class Mob;
class Level;
class Entity;
class Player;
class ItemEnchants;
#include "../../UseAnimation.h"
#include "../../util/Color.h"

class ItemInstance {
public:
	short count, aux;
	CompoundTag* userData;
	bool valid;
	Item* item;
	Block* block;

	ItemInstance();
	ItemInstance(bool);
	ItemInstance(int, int, int, const CompoundTag*);
	ItemInstance(int, int, int);
	ItemInstance(const Item*);
	ItemInstance(const Item*, int);
	ItemInstance(const Item*, int, int);
	ItemInstance(const Item*, int, int, const CompoundTag*);
	ItemInstance(const Block*);
	ItemInstance(const Block*, int);
	ItemInstance(const Block*, int, int);
	ItemInstance(const ItemInstance&);
	
	const ItemInstance& operator=(const ItemInstance&);
	const ItemInstance& operator==(const ItemInstance&);
	const ItemInstance& operator!=(const ItemInstance&);
	
	bool isThrowable() const;
	UseAnimation getUseAnimation() const;
	std::string getHoverName() const;
	std::string getEffectName() const;
	bool isNull() const;
	void getIcon(int, bool) const;
	bool isGlint() const;
	bool isDamaged() const;
	void setUserData(std::unique_ptr<CompoundTag, std::default_delete<CompoundTag>>);
	bool isStackable(const ItemInstance*, const ItemInstance*);
	void onCraftedBy(Level&, Player&);
	void add(int);
	void setNull();
	void cloneSafe(const ItemInstance*);
	short getAuxValue() const;
	void getUserData() const;
	void sameItemAndAux(const ItemInstance*) const;
	int getMaxStackSize() const;
	std::string getName() const;
	int getId() const;
	bool matchesNulls(const ItemInstance*, const ItemInstance*);
	void remove(int);
	bool isStackable() const;
	int getMaxDamage() const;
	int getDamageValue() const;
	bool isDamageableItem() const;
	int getIdAuxEnchanted() const;
	std::string getFormattedHovertext(const Player&, bool) const;
	Color getColor() const;
	bool isEnchanted() const;
	int getEnchantValue() const;
	void getEnchantsFromUserData();
	bool matches(const ItemInstance*, const ItemInstance*);
	bool isLiquidClipItem();
	void setAuxValue(short);
	bool isWearable(const ItemInstance*);
	void set(int);
	int getMaxUseDuration() const;
	bool isArmorItem(const ItemInstance*);
	bool hasCustomHoverName() const;
	bool isStackedByData();
	bool isItem(const ItemInstance*);
	void save();
	void fromTag(const CompoundTag&);
	bool hasUserData() const;
	void setCustomName(const std::string&);
	void setRepairCost(int);
	void resetHoverName();
	bool isEnchantingBook() const;
	int getBaseRepairCost() const;
	bool isPotionItem(const ItemInstance*);
	void hurtAndBreak(int, Mob*);
	void interactEnemy(Mob*, Player*);
	void load(const CompoundTag*);
	int getAttackDamage();
	int getIdAux() const;
	void inventoryTick(Level&, Entity&, int, bool);
	float getDestroySpeed(Block*);
	bool canDestroySpecial(Block*);
	bool hasSameUserData(const ItemInstance&) const;
	void releaseUsing(Player*, int);
	void useTimeDepleted(Level*, Player*);
	void hurtEnemy(Mob*, Mob*);
	bool use(Player&);
	bool useOn(Player*, int, int, int, signed char, float, float, float);
	void mineBlock(BlockID, int, int, int, Mob*);
	void clone(const ItemInstance*);
	std::string getCustomName() const;
	void saveEnchantsToUserData(const ItemEnchants&);
	void getUserNetworkData();
	bool isHorseArmorItem(const ItemInstance*);
	void setDescriptionId(const std::string&);
	void init(int, int, int);
	void snap(Player*);
	void _setItem(int);
	bool useAsFuel();
	bool isFullStack() const;
	int getEnchantSlot() const;
	void _getHoverTExtFomattingPrefix() const;
	void toString() const;
};
