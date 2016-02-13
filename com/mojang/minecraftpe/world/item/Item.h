#pragma once
#include <string>

class IDataOutput;
class TextureUVCoordinateSet;
class CreativeItemCategory;
class UseAnimation;
class Block;
class ItemInstance;
class Player;
class BlockSource;
class Container;
class Vec3;
class Level;
class Mob;
class BlockID;
class IDataInput;
class Entity;

namespace Json
{
    class Value;
};

class Item
{
public:

    unsigned char maxStackSize; //4
    char filler1[10]; //8
    short itemId; //18
    std::string name; //20
    short maxDamage; //24
    short properties; //26
    int maxUseDuration; //28
    int useAnimation; //32
    int creativeCategory; //36
    char filler2[8]; //40
    TextureUVCoordinateSet& icon; //48
    char filler3[16]; //52
    static Item* mItems[4096];

    Item(const std::string&, short);

    virtual ~Item();
    virtual Item* setIcon(const std::string&, int);
    virtual Item* setIcon(const TextureUVCoordinateSet&);
    virtual void setMaxStackSize(unsigned char);
    virtual void setCategory(CreativeItemCategory);
    virtual void setStackedByData(bool);
    virtual void setMaxDamage(int);
    virtual void setHandEquipped();
    virtual void setUseAnimation(UseAnimation);
    virtual void setMaxUseDuration(int);
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
    virtual const std::string buildDescriptionName(const ItemInstance&) const;
    virtual const std::string buildEffectDescriptionName(const ItemInstance&) const;
    virtual void readUserData(ItemInstance*, IDataInput&) const;
    virtual void writeUserData(const ItemInstance*, IDataOutput&, bool) const;
    virtual int getMaxStackSize(const ItemInstance*);
    virtual void inventoryTick(ItemInstance&, Level&, Entity&, int, bool);
    virtual void onCraftedBy(ItemInstance&, Level&, Player&);
    virtual const std::string getInteractText() const;
    virtual int getAnimationFrameFor(Mob&) const;
    virtual bool isEmissive(int) const;
    virtual TextureUVCoordinateSet& getIcon(int, int, bool) const;
    virtual int getIconYOffset() const;
    virtual bool isMirroredArt() const;

    void init(Json::Value&); //0054b130

    static TextureUVCoordinateSet getTextureUVCoordinateSet(const std::string&, int); //0051c12c
    static void addCreativeItem(const ItemInstance&); //00541EF8
    static void addCreativeItem(short, short); //00541f28
    static void addCreativeItem(Block*, short); //00541f50
    static void addCreativeItem(Item*, short); //00541f78
    static void initCreativeItems(); //00541fa4
    static void initItems(); //0055b0b4
    static void addBlockItems(); //0055f9c0

};

