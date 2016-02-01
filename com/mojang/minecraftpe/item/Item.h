#pragma once
#include <string>
enum CreativeItemCategory;
enum UseAnimation;

class Item {
public:

    Item(std::string, short);

    virtual ~Item();
    virtual Item* setIcon(const std::string&, int);
    virtual Item* setIcon(const TextureUVCoordinateSet&);
    virtual void setMaxStackSize(unsigned char);
    virtual void setCategory(CreativeItemCategory);
    virtual void setStackedByData(bool);
    virtual void setMaxDamage(int);
    virtual void setHandEquipped();
    virtual void setUseAnimation(UseAnimation);
    virtual void setMaxDuration(int);
    virtual bool canBeDepleted();
    virtual bool canDestroySpecial(const Block*) const;
    virtual int getLevelDataForAuxValue(int) const;
    virtual bool isStackedByData() const;
    virtual int getMaxDamage();
    virtual int getAttackDamage();
    virtual bool isHandEquipped() const;
    virtual bool isArmor() const;
    virtual bool isDye() const;
    virtual bool isFoil(const ItemInstance*) const;
    virtual bool isThrowable() const;
    virtual bool canDestroyInCreative() const;
    virtual bool isLiquidClipItem(int) const;
    virtual bool requiresInteract() const;
    virtual const std::string& appendFormattedHovertext(const ItemInstance&, const Player&, std::string&, bool) const;
    virtual bool isValidRepairItem(const ItemInstance&, const ItemInstance&);
    virtual int getEnchantSlot() const;
    virtual int getEnchantValue() const;
    virtual bool isComplex() const;
    virtual int getColor(const ItemInstance&) const;
    virtual bool use(ItemInstance&, Player&);
    virtual bool useOn(ItemInstance*, Player*, int, int, int, signed char, float, float, float);
    virtual void dispense(BlockSource&, Container&, int, const Vec3&, signed char);
    virtual void useTimeDepleted(ItemInstance*, Level*, Player*);
    virtual void releaseUsing(ItemInstance*, Player*, int);
    virtual float getDestroySpeed(ItemInstance*, Block*);
    virtual void hurtEnemy(ItemInstance*, Mob*, Mob*);
    virtual void interactEnemy(ItemInstance*, Mob*, Player*);
    virtual void mineBlock(ItemInstance*, BlockID, int, int, int, Mob*);
    virtual const std::string& buildDescriptionName(const ItemInstance&) const;
    virtual const std::string& buildEffectDescriptionName(const ItemInstance&) const;
    virtual void readUserData(ItemInstance*, IDataInput&) const;
    virtual void writeUserData(const ItemInstance*, IDataOutput&, bool) const;
    virtual int getMaxStackSize(const ItemInstance*);
    virtual void inventoryTick(ItemInstance&, Level&, Entity&);
    virtual void onCraftedBy(ItemInstance&, Level&, Player&);
    virtual const std::string& getInteractText() const;
    virtual int getAnimationFrameFor(Mob&) const;
    virtual bool isEmissive(int) const;
    virtual const TextureUVCoordinateSet& getIcon(int, int, bool) const;
    virtual int getIconYOffset() const;
    virtual bool isMirroredArt() const;
};
