#pragma once

#include <string>
#include <memory>
#include <vector>

#include "../../CreativeItemCategory.h"
#include "../../CommonTypes.h"
#include "../../UseAnimation.h"
#include "../level/block/BlockShape.h"

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
class Color;
struct Vec3;
struct IDataInput;
struct IDataOutput;
class Color;
class Random;
class ResourcePackManager;
namespace Json { class Value; };

class Item {
public:
	class Tier {
	public:
		ItemInstance* getTierItem() const;

		static Tier* WOOD;
		static Tier* STONE;
		static Tier* IRON;
		static Tier* GOLD;
		static Tier* DIAMOND;
	};

	/* copy constructor */
	Item(const std::string&, short);

	/* fields */
	char filler[200];

	/* list */
	static Item* mItems[4096];
	static std::vector<ItemInstance> mCreativeList;
	static Random* mRandom;

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
	virtual void setRequiresWorldBuilder(bool);
	virtual void setExplodable(bool);
	virtual void setIsGlint(bool);
	virtual void setShouldDespawn(bool);
	virtual BlockShape getBlockShape() const;
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
	virtual const std::string& appendFormattedHovertext(const ItemInstance&, Level&, std::string&, bool) const;
	virtual bool isValidRepairItem(const ItemInstance&, const ItemInstance&);
	virtual int getEnchantSlot() const;
	virtual int getEnchantValue() const;
	virtual bool isComplex() const;
	virtual int uniqueAuxValues() const;
	virtual Color getColor(const ItemInstance&) const;
	virtual bool use(ItemInstance&, Player&);
	virtual bool useOn(ItemInstance&, Entity&, int, int, int, signed char, float, float, float);
	virtual void dispense(BlockSource&, Container&, int, const Vec3&, signed char);
	virtual void useTimeDepleted(ItemInstance*, Level*, Player*);
	virtual void releaseUsing(ItemInstance*, Player*, int);
	virtual float getDestroySpeed(ItemInstance*, const Block*);
	virtual void hurtEnemy(ItemInstance*, Mob*, Mob*);
	virtual void interactEnemy(ItemInstance*, Mob*, Player*);
	virtual void mineBlock(ItemInstance*, BlockID, int, int, int, Entity*);
	virtual const std::string buildDescriptionName(const ItemInstance&) const;
	virtual const std::string buildEffectDescriptionName(const ItemInstance&) const;
	virtual void readUserData(ItemInstance*, IDataInput&) const;
	virtual void writeUserData(const ItemInstance*, IDataOutput&) const;
	virtual int getMaxStackSize(const ItemInstance*);
	virtual void inventoryTick(ItemInstance&, Level&, Entity&, int, bool);
	virtual void onCraftedBy(ItemInstance&, Level&, Player&);
	virtual int getCooldownType() const;
	virtual int getCooldownTime() const;
	virtual const std::string& getInteractText(const Player&) const;
	virtual int getAnimationFrameFor(Mob&) const;
	virtual bool isEmissive(int) const;
	virtual const TextureUVCoordinateSet& getIcon(int, int, bool) const;
	virtual int getIconYOffset() const;
	virtual bool isMirroredArt() const;

	void init(Json::Value&);

	/* static function */
	static TextureUVCoordinateSet getTextureUVCoordinateSet(const std::string&, int);
	static void initClientData();
	static void initServerData(ResourcePackManager&);
	static void initClient(Json::Value&, Json::Value&);
	static void initServer(Json::Value&);
	static void addBlockItems();
	static void initCreativeItems();
	static void addCreativeItem(Block*, short);
	static void addCreativeItem(Item*, short);
	static void addCreativeItem(const ItemInstance&);
	static void addCreativeItem(short, short);
	static void registerItems();

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
	static Item* mFilledMap; // 358
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
	static Item* mGold_nugget; // 371
	static Item* mNether_wart; // 372
	static Item* mPotion; // 373
	static Item* mGlass_bottle; // 374
	static Item* mSpider_eye; // 375
	static Item* mFermented_spider_eye; // 376
	static Item* mBlazePowder; // 377
	static Item* mMagma_cream; // 378
	static Item* mBrewing_stand; // 379
	static Item* mCauldron; // 380
	static Item* mEnderEye; // 381
	static Item* mSpeckled_melon; // 382
	static Item* mMobPlacer; // 383
	static Item* mExperiencePotionItem; // 384
	static Item* mFireCharge; // 385
	static Item* mEmerald; // 388
	static Item* mItemFrame; // 389
	static Item* mFlowerPot; // 390
	static Item* mCarrot; // 391
	static Item* mPotato; // 392
	static Item* mPotatoBaked; // 393
	static Item* mPoisonous_potato; // 394
	static Item* mEmptyMap; // 395
	static Item* mGoldenCarrot; // 396

};
