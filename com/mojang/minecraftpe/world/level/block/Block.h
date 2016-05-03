#pragma once
#include <string>
#include <vector>
#include <memory>
class Material;
class BlockEntity;
struct BlockPos;
class BlockSource;
class Entity;
class ItemInstance;
class Player;
class Mob;
class Random;
struct Vec3;
class Brightness;
class TextureAtlas;
class Container;
#include "../../../client/renderer/texture/TextureUVCoordinateSet.h"
#include "../../../client/renderer/texture/TextureAtlasTextureItem.h"
#include "../../util/Color.h"
#include "../../phys/AABB.h"
#include "../../../CommonTypes.h"
#include "entity/BlockEntityType.h"
#include "BlockShape.h"
#include "../../../CreativeItemCategory.h"

class Block {
public:
	class SoundType {
	public:
		float volume; // 0
		float pitch; // 4
		std::string stepSound; // 8
		std::string breakSound; // 12
		std::string placeSound; // 16

		SoundType(const std::string&, float, float);
		SoundType(const std::string&, const std::string&, float, float);
		SoundType(const std::string&, const std::string&, const std::string&, float, float);
		
		~SoundType();
		
		float getVolume() const;
		float getPitch() const;
		std::string getStepSound() const;
		std::string getBreakSound() const;
		std::string getPlaceSound() const;
	};


	BlockID blockId; // 4
	unsigned int textureIsotropic; // 8
	std::string name; // 12
	TextureUVCoordinateSet texture; // 16
	const Block::SoundType& soundType; // 44
	bool replaceable;
	bool canBuildOver; // 49
	int renderLayer; // 52
	BlockShape blockShape; // 56
	int properties; // 60
	BlockEntityType blockEntityType; // 64
	bool animates; // 68
	float thickness; // 72
	bool slippery; // 76
	bool instaTicks; // 77
	float gravity; // 80
	Material& material; // 84
	Color mapColor; // 88
	float friction; // 104
	bool heavy; // 108
	float hardness; // 112
	float explosionResistance; // 116
	CreativeItemCategory creativeCategory; // 120
	AABB hitbox; // 124


	static std::shared_ptr<TextureAtlas> mTerrainTextureAtlas;
	static std::vector<std::unique_ptr<Block>> mOwnedBlocks;
	static Block* mBlocks[256];
	static bool mSolid[256];
	static float mTranslucency[256];
	static uint8_t mLightBlock[256];
	static int mLightEmission[256];
	static bool mShouldTick[256];


	static const Block::SoundType SOUND_ANVIL;
	static const Block::SoundType SOUND_CLOTH;
	static const Block::SoundType SOUND_GLASS;
	static const Block::SoundType SOUND_GRASS;
	static const Block::SoundType SOUND_GRAVEL;
	static const Block::SoundType SOUND_LADDER;
	static const Block::SoundType SOUND_METAL;
	static const Block::SoundType SOUND_NORMAL;
	static const Block::SoundType SOUND_SAND;
	static const Block::SoundType SOUND_SILENT;
	static const Block::SoundType SOUND_SLIME;
	static const Block::SoundType SOUND_SNOW;
	static const Block::SoundType SOUND_STONE;
	static const Block::SoundType SOUND_WOOD;

	Block(const Block&);
	Block(const std::string&, int, const Material&);
	Block(const std::string&, int, TextureUVCoordinateSet, const Material&);
	Block(const std::string&, int, const std::string&, const Material&);

	/* vtable */
	virtual ~Block();
	virtual void tick(BlockSource&, const BlockPos&, Random&);
	virtual const AABB& getCollisionShape(AABB&, BlockSource&, const BlockPos&, Entity*);
	virtual bool isObstructingChests(BlockSource&, const BlockPos&);
	virtual void randomlyModifyPosition(const BlockPos&, int&) const;
	virtual void randomlyModifyPosition(const BlockPos&) const;
	virtual const TextureUVCoordinateSet& getCarriedTexture(signed char, int);
	virtual bool addAABBs(BlockSource&, const BlockPos&, const AABB*, std::vector<AABB>&);
	virtual const AABB& getAABB(BlockSource&, const BlockPos&, AABB&, int, bool, int);
	virtual bool addCollisionShapes(BlockSource&, const BlockPos&, const AABB*, std::vector<AABB>&, Entity*);
	virtual bool isCropBlock() const;
	virtual bool isContainerBlock() const;
	virtual bool isCraftingBlock() const;
	virtual bool isInteractiveBlock() const;
	virtual bool isWaterBlocking() const;
	virtual bool isHurtableBlock() const;
	virtual bool isDoorBlock() const;
	virtual bool isRedstoneBlock() const;
	virtual bool isRedstoneAttachable() const;
	virtual bool isSignalSource() const;
	virtual int getDirectSignal(BlockSource&, const BlockPos&, int);
	virtual bool waterSpreadCausesSpawn() const;
	virtual void handleRain(BlockSource&, const BlockPos&, float) const;
	virtual float getThickness() const;
	virtual bool checkIsPathable(Entity&, const BlockPos&, const BlockPos&);
	virtual void dispense(BlockSource&, Container&, int, const Vec3&, signed char);
	virtual void onPlace(BlockSource&, const BlockPos&);
	virtual void onRemove(BlockSource&, const BlockPos&);
	virtual void onExploded(BlockSource&, const BlockPos&, Entity*);
	virtual void onStepOn(Entity&, const BlockPos&);
	virtual void onFallOn(BlockSource&, const BlockPos&, Entity*, float);
	virtual void onRedstoneUpdate(BlockSource&, const BlockPos&, int, bool);
	virtual void onLoaded(BlockSource&, const BlockPos&);
	virtual void getRedstoneProperty(BlockSource&, const BlockPos&);
	virtual void updateEntityAfterFallOn(Entity&);
	virtual void onFertilized(BlockSource&, const BlockPos&, Player*);
	virtual bool mayConsumeFertilizer(BlockSource&);
	virtual bool mayPick();
	virtual bool mayPick(BlockSource&, int, bool);
	virtual bool mayPlace(BlockSource&, const BlockPos&, signed char);
	virtual bool mayPlace(BlockSource&, const BlockPos&);
	virtual bool mayPlaceOn(const Block&);
	virtual void tryToPlace(BlockSource&, const BlockPos&, unsigned char);
	virtual void destroy(BlockSource&, const BlockPos&, int, Entity*);
	virtual void playerWillDestroy(Player&, const BlockPos&, int);
	virtual void neighborChanged(BlockSource&, const BlockPos&, const BlockPos&);
	virtual void getSecondPart(BlockSource&, const BlockPos&, BlockPos&);
	virtual int getResource(Random&, int, int);
	virtual int getResourceCount(Random&, int, int);
	virtual ItemInstance& asItemInstance(BlockSource&, const BlockPos&, int) const;
	virtual float getDestroyProgress(Player&);
	virtual void spawnResources(BlockSource&, const BlockPos&, int, float, int);
	virtual void spawnBurnResources(BlockSource&, float, float, float);
	virtual float getExplosionResistance(Entity*);
	virtual void clip(BlockSource&, const BlockPos&, const Vec3&, const Vec3&, bool, int);
	virtual bool use(Player&, const BlockPos&);
	virtual int getPlacementDataValue(Mob&, const BlockPos&, signed char, const Vec3&, int);
	virtual void attack(Player*, const BlockPos&);
	virtual void handleEntityInside(BlockSource&, const BlockPos&, Entity*, Vec3&);
	virtual bool entityInside(BlockSource&, const BlockPos&, Entity&);
	virtual void playerDestroy(Player*, const BlockPos&, int);
	virtual bool canSurvive(BlockSource&, const BlockPos&);
	virtual int getExperienceDrop(Random&) const;
	virtual bool canBeBuiltOver(BlockSource&, const BlockPos&) const;
	virtual void triggerEvent(BlockSource&, const BlockPos&, int, int);
	virtual TextureUVCoordinateSet getTextureNum(int);
	virtual void getMobToSpawn(BlockSource&, const BlockPos&) const;
	virtual Color getMapColor(const FullBlock&) const;
	virtual Color getMapColor() const;
	virtual bool shouldStopFalling(Entity&);
	virtual float calcGroundFriction(Mob&, const BlockPos&) const;
	virtual bool canHaveExtraData() const;
	virtual bool hasComparatorSignal();
	virtual int getComparatorSignal(BlockSource&, const BlockPos&, signed char, int);
	virtual bool shouldRenderFace(BlockSource&, const BlockPos&, signed char, const AABB&) const;
	virtual const TextureUVCoordinateSet& getTexture(signed char);
	virtual const TextureUVCoordinateSet& getTexture(signed char, int);
	virtual const TextureUVCoordinateSet& getTexture(BlockSource&, const BlockPos&, signed char);
	virtual void getTessellatedUVs();
	virtual int getIconYOffset() const;
	virtual std::string buildDescriptionName(const ItemInstance&) const;
	virtual int getColor(int) const;
	virtual int getColor(BlockSource&, const BlockPos&) const;
	virtual int getColorForParticle(BlockSource&, const BlockPos&, int) const;
	virtual bool isSeasonTinted(BlockSource&, const BlockPos&) const;
	virtual void prepareRender(BlockSource&, const BlockPos&);
	virtual void onGraphicsModeChanged(bool, bool, bool);
	virtual int getRenderLayer(BlockSource&, const BlockPos&) const;
	virtual int getExtraRenderLayers();
	virtual const AABB& getVisualShape(BlockSource&, const BlockPos&, AABB&, bool);
	virtual const AABB& getVisualShape(unsigned char, AABB&, bool);
	virtual bool animateTick(BlockSource&, const BlockPos&, Random&);
	virtual std::string getDebugText(std::vector<std::string>&);
	virtual Block* init();
	virtual bool canBeSilkTouched() const;
	virtual ItemInstance& getSilkTouchItemInstance(unsigned char);
	virtual void setVisualShape(const AABB&);
	virtual void setVisualShape(const Vec3&, const Vec3&);
	virtual Block* setSoundType(const Block::SoundType&);
	virtual Block* setLightBlock(Brightness);
	virtual Block* setLightEmission(float);
	virtual Block* setExplodeable(float);
	virtual Block* setDestroyTime(float);
	virtual Block* setFriction(float);
	virtual Block* setTicking(bool);
	virtual Block* setMapColor(const Color&);
	virtual int getSpawnResourcesAuxValue(unsigned char);

	const std::string& getDescriptionId() const;
	void addAABB(const AABB&, const AABB*, std::vector<AABB, std::allocator<AABB>>&);
	void popResource(BlockSource&, const BlockPos&, const ItemInstance&);
	Block* setCategory(CreativeItemCategory);
	void setSolid(bool);
	bool isSolid() const;
	
	static TextureAtlasTextureItem getTextureItem(const std::string&);
	static TextureUVCoordinateSet getTextureUVCoordinateSet(const std::string&, int);
	static void initBlocks();
	static void teardownBlocks();

	static Block* mAir; // 0
	static Block* mStone; // 1
	static Block* mGrass; // 2
	static Block* mDirt; // 3
	static Block* mCobblestone; // 4
	static Block* mWoodPlanks; // 5
	static Block* mSapling; // 6
	static Block* mBedrock; // 7
	static Block* mFlowingWater; // 8
	static Block* mStillWater; // 9
	static Block* mFlowingLava; // 10
	static Block* mStillLava; // 11
	static Block* mSand; // 12
	static Block* mGravel; // 13
	static Block* mGoldOre; // 14
	static Block* mIronOre; // 15
	static Block* mCoalOre; // 16
	static Block* mLog; // 17
	static Block* mLeaves; // 18
	static Block* mSponge; // 19
	static Block* mGlass; // 20
	static Block* mLapisOre; // 21
	static Block* mLapisBlock; // 22
	static Block* mDispenser; // 23
	static Block* mSandStone; // 24
	static Block* mNote; // 25
	static Block* mBed; // 26
	static Block* mGoldenRail; // 27
	static Block* mDetectorRail; // 28
	static Block* mPistonSticky; // 29
	static Block* mWeb; // 30
	static Block* mTallgrass; // 31
	static Block* mDeadBush; // 32
	static Block* mWool; // 35
	static Block* mYellowFlower; // 37
	static Block* mRedFlower; // 38
	static Block* mBrownMushroom; // 39
	static Block* mRedMushroom; // 40
	static Block* mGoldBlock; // 41
	static Block* mIronBlock; // 42
	static Block* mDoubleStoneSlab; // 43
	static Block* mStoneSlab; // 44
	static Block* mBrick; // 45
	static Block* mTNT; // 46
	static Block* mBookshelf; // 47
	static Block* mMossyCobblestone; // 48
	static Block* mObsidian; // 49
	static Block* mTorch; // 50
	static Block* mFire; // 51
	static Block* mMobSpawner; // 52
	static Block* mOakStairs; // 53
	static Block* mChest; // 54
	static Block* mRedStoneDust; // 55
	static Block* mDiamondOre; // 56
	static Block* mDiamondBlock; // 57
	static Block* mWorkBench; // 58
	static Block* mWheatCrop; // 59
	static Block* mFarmland; // 60
	static Block* mFurnace; // 61
	static Block* mLitFurnace; // 62
	static Block* mSign; // 63
	static Block* mWoodenDoor; // 64
	static Block* mLadder; // 65
	static Block* mRail; // 66
	static Block* mStoneStairs; // 67
	static Block* mWallSign; // 68
	static Block* mLever; // 69
	static Block* mStonePressurePlate; // 70
	static Block* mIronDoor; // 71
	static Block* mWoodPressurePlate; // 72
	static Block* mRedStoneOre; // 73
	static Block* mLitRedStoneOre; // 74
	static Block* mUnlitRedStoneTorch; // 75
	static Block* mLitRedStoneTorch; // 76
	static Block* mStoneButton; // 77
	static Block* mTopSnow; // 78
	static Block* mIce; // 79
	static Block* mSnow; // 80
	static Block* mCactus; // 81
	static Block* mClay; // 82
	static Block* mReeds; // 83
	static Block* mFence; // 85
	static Block* mPumpkin; // 86
	static Block* mNetherrack; // 87
	static Block* mSoulSand; // 88
	static Block* mGlowStone; // 89
	static Block* mPortal; // 90
	static Block* mLitPumpkin; // 91
	static Block* mCake; // 92
	static Block* mUnpoweredRepeater; // 93
	static Block* mPoweredRepeater; // 94
	static Block* mInvisibleBedrock; // 95
	static Block* mTrapdoor; // 96
	static Block* mMonsterStoneEgg; // 97
	static Block* mStoneBrick; // 98
	static Block* mBrownMushroomBlock; // 99
	static Block* mRedMushroomBlock; // 100
	static Block* mIronFence; // 101
	static Block* mGlassPane; // 102
	static Block* mMelon; // 103
	static Block* mPumpkinStem; // 104
	static Block* mMelonStem; // 105
	static Block* mVine; // 106
	static Block* mFenceGateOak; // 107
	static Block* mBrickStairs; // 108
	static Block* mStoneBrickStairs; // 109
	static Block* mMycelium; // 110
	static Block* mWaterlily; // 111
	static Block* mNetherBrick; // 112
	static Block* mNetherFence; // 113
	static Block* mNetherBrickStairs; // 114
	static Block* mNetherWart; // 115
	static Block* mEnchantingTable; // 116
	static Block* mBrewingStand; // 117
	static Block* mCauldron; // 118
	static Block* mEndPortalFrame; // 120
	static Block* mEndStone; // 121
	static Block* mUnlitRedStoneLamp; // 123
	static Block* mLitRedStoneLamp; // 124
	static Block* mActivatorRail; // 126
	static Block* mCocoa; // 127
	static Block* mSandStoneStairs; // 128
	static Block* mEmeraldOre; // 129
	static Block* mTripwireHook; // 131
	static Block* mTripwire; // 132
	static Block* mEmeraldBlock; // 133
	static Block* mSpruceStairs; // 134
	static Block* mBirchStairs; // 135
	static Block* mJungleStairs; // 136
	static Block* mCobblestoneWall; // 139
	static Block* mFlowerPot; // 140
	static Block* mCarrotCrop; // 141
	static Block* mPotatoCrop; // 142
	static Block* mWoodButton; // 143
	static Block* mSkull; // 144
	static Block* mAnvil; // 145
	static Block* mTrappedChest; // 146
	static Block* mLightWeightedPressurePlate; // 147
	static Block* mHeavyWeightedPressurePlate; // 148
	static Block* mUnpoweredComparator; // 149
	static Block* mPoweredComparator; // 150
	static Block* mDaylightDetector; // 151
	static Block* mRedstoneBlock; // 152
	static Block* mQuartzOre; // 153
	static Block* mHopper; // 154
	static Block* mQuartzBlock; // 155
	static Block* mQuartzStairs; // 156
	static Block* mDoubleWoodenSlab; // 157
	static Block* mWoodenSlab; // 158
	static Block* mStainedClay; // 159
	static Block* mLeaves2; // 161
	static Block* mLog2; // 162
	static Block* mAcaciaStairs; // 163
	static Block* mDarkOakStairs; // 164
	static Block* mSlimeBlock; // 165
	static Block* mIronTrapdoor; // 167
	static Block* mHayBlock; // 170
	static Block* mWoolCarpet; // 171
	static Block* mHardenedClay; // 172
	static Block* mCoalBlock; // 173
	static Block* mPackedIce; // 174
	static Block* mDoublePlant; // 175
	static Block* mDaylightDetectorInverted; // 178
	static Block* mRedSandstone; // 179
	static Block* mRedSandstoneStairs; // 180
	static Block* mDoubleStoneSlab2; // 181
	static Block* mStoneSlab2; // 182
	static Block* mSpuceFenceGate; // 183
	static Block* mBirchFenceGate; // 184
	static Block* mJungleFenceGate; // 185
	static Block* mDarkOakFenceGate; // 186
	static Block* mAcaciaFenceGate; // 187
	static Block* mWoodenDoorSpruce; // 193
	static Block* mWoodenDoorBirch; // 194
	static Block* mWoodenDoorJungle; // 195
	static Block* mWoodenDoorAcacia; // 196
	static Block* mWoodenDoorDarkOak; // 197
	static Block* mGrassPathBlock; // 198
	static Block* mItemFrame; // 199
	static Block* mPodzol; // 243
	static Block* mBeetrootCrop; // 244
	static Block* mStonecutterBench; // 245
	static Block* mGlowingObsidian; // 246
	static Block* mNetherReactor; // 247
	static Block* mInfoUpdateGame1; // 248
	static Block* mInfoUpdateGame2; // 249
	static Block* mInfoReserved6; // 255
};
