#pragma once

#include <memory>
#include "../../UseAnimation.h"

class CompoundTag;
class Item;
class Block;
class ItemEnchants;
class Mob;
class Player;
class Level;
class Entity;

class ItemInstance {
public:
    unsigned char count;
    unsigned short aux;
    CompoundTag* userData;
    bool valid;
    Item* item;
    Block* block;

	ItemInstance();
	ItemInstance(const Block*);
	ItemInstance(const Block*, int);
	ItemInstance(const Block*, int, int);
	ItemInstance(const Item*);
	ItemInstance(const Item*, int);
	ItemInstance(const Item*, int, int);
	ItemInstance(const Item*, int, int, const CompoundTag*);
	ItemInstance(const ItemInstance&);
	ItemInstance(bool);
	ItemInstance(int ,int, int);
	ItemInstance(int, int, int, const CompoundTag*);

    void _getHoverFormattingPrefix();
    void _setItem(int);
    void add(int);
    bool canDestroySpecial(Block *);
    int getAttackDamage();
    int getAuxValue() const;
    int getBaseRepairCost();
    std::string getCustomName() const;
    int getDamageValue() const;
    float getDestroySpeed(Block *);
    std::string getEffectName()const;
    int getEnchantSlot();
    int getEnchantValue();
    void getEnchantsFromUserData();
    void getFormattedHovertext();
    std::string getHoverName() const;
    void getIcon(int, bool);
    int getId() const;
    int getIdAux();
    void getIdAuxEnchanted();
    int getMaxDamage() const;
    int getMaxStackSize() const;
    int getMaxUseDuration();
    void getName();
    void getNetworkUserData();
    UseAnimation getUseAnimation() const;
    void getUserData();
    bool hasCustomHoverName();
    bool hasSameUserData(const ItemInstance&);
    bool hasUserData();
    void hurtAndBreak(int, Entity*);
    void hurtEnemy(Mob*, Mob*);
    void init(int, int, int);
    void interactEnemy(Mob*,Player*);
    bool isArmorItem(const ItemInstance*);
    bool isDamageableItem();
    bool isDamaged() const;
    bool isEnchanted();
    bool isEnchantingBook();
    bool isFoil();
    bool isFullStack();
    bool isItem(const ItemInstance*);
    bool isLiquidClipItem();
    bool isNull();
    bool isStackable(const ItemInstance*, const ItemInstance*);
    bool isStackable();
    bool isStackedByData();
    bool isThrowable();
    void load(const CompoundTag&);
    void matches(ItemInstance*);
    void matches(const ItemInstance*, const ItemInstance*);
    void matchesNulls(const ItemInstance*, const ItemInstance*);
    void operator!=(const ItemInstance&);
    void operator=(const ItemInstance&);
    void operator==(const ItemInstance&);
    void releaseUsing(Player*, int);
    void remove(int);
    void resetHoverName();
    bool sameItemAndAux(const ItemInstance*) const;
    CompoundTag* save();
    void saveEnchantsToUserData(ItemEnchants const&);
    void set(int);
    void setAuxValue(short);
    void setCustomName(const std::string&);
    void setDescriptionId(const std::string&);
    void setNull();
    void setRepairCost(int);
    void setUserData(std::unique_ptr<CompoundTag>);
    void snap(Player*);
    void toString();
    void use(Player&);
    void useAsFuel();
    void useOn(Player*, int, int, int, signed char, float, float, float);
    void useTimeDepleted(Level*,Player*);
	void onCraftedBy(Level&, Player&);

    static ItemInstance* clone(ItemInstance const*);
    static ItemInstance* cloneSafe(ItemInstance const*);
    static ItemInstance* fromTag(CompoundTag const&);
};
