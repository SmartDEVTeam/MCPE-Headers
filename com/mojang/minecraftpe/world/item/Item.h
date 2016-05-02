#pragma once

#include <string>
#include <memory>

#include "../../CreativeItemCategory.h"
#include "../../CommonTypes.h"
#include "../../UseAnimation.h"

class TextureUVCoordinateSet;
struct SeedItemComponent;
class FoodItemComponent;
class CameraItemComponent;
class Block;
class ItemInstance;
class Entity;
class Mob;
class Level;
class Player;
class Container;
class BlockSource;
struct Vec3;
struct IDataInput;
struct IDataOutput;
namespace Json { class Value; };

class Item {
public:
	/* constructor */
	Item(const std::string&, short);

	/* fields */
	uint8_t _maxStackSize; // 4
	std::string atlas; // 8
	int frameCount; // 12
	short idk2; // 16
	short itemId; // 18
	std::string name; // 20
	short maxDamage; // 24
	short properties; // 26
	int useDuration; // 28
	BlockID blockId; // 32
	UseAnimation useAnimation; // 33
	CreativeItemCategory creativeCategory; // 36
	int idk3; // 40
	int hoverTextColor; // 44
	TextureUVCoordinateSet& icon; // 48
	int idk5; // 52
	std::unique_ptr<FoodItemComponent> _foodDetails; // 56
	std::unique_ptr<SeedItemComponent> _seedDetails; // 60

	/* list */
	static Item* mItems[4096];

	/* vtable */
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
	virtual const std::string& getInteractText() const;
	virtual int getAnimationFrameFor(Mob&) const;
	virtual bool isEmissive(int) const;
	virtual const TextureUVCoordinateSet& getIcon(int, int, bool) const;
	virtual int getIconYOffset() const;
	virtual bool isMirroredArt() const;

	/* member functions */
	void init(Json::Value&);

	/* static functions */
	static TextureUVCoordinateSet getTextureUVCoordinateSet(const std::string&, int);
	static void initItems();
	static void addBlockItems();
	static void initCreativeItems();
	static void addCreativeItem(Block*, short);
	static void addCreativeItem(Item*, short);
	static void addCreativeItem(const ItemInstance&);
	static void addCreativeItem(short, short);
};
