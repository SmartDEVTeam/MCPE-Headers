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
class Color;
class Random;
namespace Json { class Value; };

class Item {
public:
	uint8_t _maxStackSize; // 4
	std::string atlas; // 8
	int frameCount; // 12
	short idk; // 16
	short itemId; // 18
	std::string name; // 20
	short maxDamage; // 24
	bool foil; // 26
	bool handEquipped; // 27
	bool stackedByData; // 28
	int useDuration; // 32
	BlockID blockId; // 36
	UseAnimation useAnimation; // 37
	CreativeItemCategory creativeCategory; // 40
	int idk1; // 44
	std::string hoverTextColor; // 48
	TextureUVCoordinateSet& icon; // 52
	int idk2; // 56
	std::unique_ptr<FoodItemComponent> _foodDetails; // 60
	std::unique_ptr<SeedItemComponent> _seedDetails; // 64

	static Item* mItems[4096];
	static Random* mRandom;

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
	virtual bool isGlint(const ItemInstance*) const;
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
	virtual const std::string& getInteractText(const Player&) const;
	virtual int getAnimationFrameFor(Mob&) const;
	virtual bool isEmissive(int) const;
	virtual const TextureUVCoordinateSet& getIcon(int, int, bool) const;
	virtual int getIconYOffset() const;
	virtual bool isMirroredArt() const;

	void init(Json::Value&);

	static TextureUVCoordinateSet getTextureUVCoordinateSet(const std::string&, int);
	static void initItems();
	static void addBlockItems();
	static void initCreativeItems();
	static void addCreativeItem(Block*, short);
	static void addCreativeItem(Item*, short);
	static void addCreativeItem(const ItemInstance&);
	static void addCreativeItem(short, short);

	static Item* mShovel_iron; // 256
	static Item* mPickaxe_iron; // 257
	static Item* mHatchet_iron; // 258
	static Item* mFlintAndSteel; // 259
	static Item* mApple; // 260
	static Item* mBow; // 261
	static Item* mArrow; // 262
	static Item* mCoal; // 263
	static Item* mDiamond; // 264
	static Item* mIronIngot; // 265
	static Item* mGoldIngot; // 266
	static Item* mSword_iron; // 267
	static Item* mSword_wood; // 268
	static Item* mShovel_wood; // 269
	static Item* mPickaxe_wood; // 270
	static Item* mHatchet_wood; // 271
	static Item* mSword_stone; // 272
	static Item* mShovel_stone; // 273
	static Item* mPickaxe_stone; // 274
	static Item* mHatchet_stone; // 275
	static Item* mSword_diamond; // 276
	static Item* mShovel_diamond; // 277
	static Item* mPickaxe_diamond; // 278
	static Item* mHatchet_diamond; // 279
	static Item* mStick; // 280
	static Item* mBowl; // 281
	static Item* mMushroomStew; // 282
	static Item* mSword_gold; // 283
	static Item* mShovel_gold; // 284
	static Item* mPickaxe_gold; // 285
	static Item* mHatchet_gold; // 286
	static Item* mString; // 287
	static Item* mFeather; // 288
	static Item* mSulphur; // 289
	static Item* mHoe_wood; // 290
	static Item* mHoe_stone; // 291
	static Item* mHoe_iron; // 292
	static Item* mHoe_diamond; // 293
	static Item* mHoe_gold; // 294
	static Item* mSeeds_wheat; // 295
	static Item* mWheat; // 296
	static Item* mBread; // 297
	static Item* mHelmet_cloth; // 298
	static Item* mChestplate_cloth; // 299
	static Item* mLeggings_cloth; // 300
	static Item* mBoots_cloth; // 301
	static Item* mHelmet_chain; // 302
	static Item* mChestplate_chain; // 303
	static Item* mLeggings_chain; // 304
	static Item* mBoots_chain; // 305
	static Item* mHelmet_iron; // 306
	static Item* mChestplate_iron; // 307
	static Item* mLeggings_iron; // 308
	static Item* mBoots_iron; // 309
	static Item* mHelmet_diamond; // 310
	static Item* mChestplate_diamond; // 311
	static Item* mLeggings_diamond; // 312
	static Item* mBoots_diamond; // 313
	static Item* mHelmet_gold; // 314
	static Item* mChestplate_gold; // 315
	static Item* mLeggings_gold; // 316
	static Item* mBoots_gold; // 317
	static Item* mFlint; // 318
	static Item* mPorkChop_raw; // 319
	static Item* mPorkChop_cooked; // 320
	static Item* mPainting; // 321
	static Item* mApple_gold; // 322
	static Item* mSign; // 323
	static Item* mDoor_wood; // 324
	static Item* mBucket; // 325
	static Item* mMinecart; // 328
	static Item* mSaddle; // 329
	static Item* mDoor_iron; // 330
	static Item* mRedStone; // 331
	static Item* mSnowball; // 332
	static Item* mBoat; // 333
	static Item* mLeather; // 334
	static Item* mBrick; // 336
	static Item* mClay; // 337
	static Item* mReeds; // 338
	static Item* mPaper; // 339
	static Item* mBook; // 340
	static Item* mSlimeBall; // 341
	static Item* mChestMinecart; // 342
	static Item* mEgg; // 344
	static Item* mCompass; // 345
	static Item* mFishingRod; // 346
	static Item* mClock; // 347
	static Item* mYellowDust; // 348
	static Item* mFish_raw_cod; // 349
	static Item* mFish_raw_salmon; // 349, 1
	static Item* mFish_raw_clownfish; // 349, 2
	static Item* mFish_raw_pufferfish; // 349, 3
	static Item* mFish_cooked_cod; // 350
	static Item* mFish_cooked_salmon; // 350, 1
	static Item* mDye; // 351
	static Item* mBone; // 352
	static Item* mSugar; // 353
	static Item* mCake; // 354
	static Item* mBed; // 355
	static Item* mRepeater; // 356
	static Item* mCookie; // 357
	static Item* mEmptyMap; // 358
	static Item* mShears; // 359
	static Item* mMelon; // 360
	static Item* mSeeds_pumpkin; // 361
	static Item* mSeeds_melon; // 362
	static Item* mBeef_raw; // 363
	static Item* mBeef_cooked; // 364
	static Item* mChicken_raw; // 365
	static Item* mChicken_cooked; // 366
	static Item* mRotten_flesh; // 367
	static Item* mBlazeRod; // 369
	static Item* mGhast_tear; // 370
};
