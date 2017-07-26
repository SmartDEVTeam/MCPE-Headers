#pragma once

#include <string>
#include <vector>
#include <memory>
#include <unordered_map>

#include "../../../client/render/TextureUVCoordinateSet.h"
#include "../../../util/Color.h"
#include "../../phys/AABB.h"
#include "../../material/Material.h"
#include "BlockShape.h"
#include "BlockState.h"
#include "../../item/CreativeItemCategory.h"
#include "BlockSupportType.h"
#include "entity/BlockEntityType.h"
#include "BlockID.h"
#include "../../../util/Util.h"

class BlockEntity;
class Container;
class FullBlock;
struct BlockPos;
class BlockSource;
class Entity;
class Mob;
class Player;
class ItemInstance;
class Random;
struct Vec3;
class Brightness;
enum class BlockRenderLayer;

class Block
{
public:
	/* fields */
	BlockID blockId; // 4
	std::string descriptionId; // 8
	std::string descriptionName; // 12
	bool replaceable; // 16
	bool canBuildOver; // 17
	short filler1; // 18
	BlockRenderLayer renderLayer; // 20
	std::vector<BlockProperty> properties; // 24
	BlockEntityType blockEntityType; // 28
	bool animates; // 32
	char filler2[3]; // 33
	float idk; // 36
	float thickness; // 40
	bool slippery; // 44
	bool instaTicks; // 45
	short filler3; // 46
	float gravity; // 48
	Material& material; // 52
	Color mapColor[4]; // 56
	bool heavy; // 76
	char filler4[6]; // 77
	float particleQuantity; // 80
	float destroyTime; // 84
	float explosionResistance; // 88
	CreativeItemCategory creativeCategory; // 92
	bool allowRunes; // 96
	char filler5[31]; // 97
	int bitsUsed; // 128
	BlockState blockStates[42]; // 132

	Block(const std::string&, int, const Material&);

	/* vtable */
	virtual ~Block();
	virtual bool tick(BlockSource&, const BlockPos&, Random&) const;
	virtual const AABB& getCollisionShape(AABB&, BlockSource&, const BlockPos&, Entity*) const;
	virtual bool isObstructingChests(BlockSource&, const BlockPos&) const;
	virtual const Vec3& randomlyModifyPosition(const BlockPos&, int&) const;
	virtual const Vec3& randomlyModifyPosition(const BlockPos&) const;
	virtual void addAABBs(BlockSource&, const BlockPos&, const AABB*, std::vector<AABB, std::allocator<AABB>>&) const;
	virtual const AABB& getAABB(BlockSource&, const BlockPos&, AABB&, int, bool, int) const;
	virtual void addCollisionShapes(BlockSource&, const BlockPos&, const AABB*, std::vector<AABB, std::allocator<AABB>>&, Entity*) const;
	virtual bool canProvideSupport(BlockSource&, const BlockPos&, signed char, BlockSupportType) const;
	virtual bool isInfiniburnBlock(int) const;
	virtual bool isCropBlock() const;
	virtual bool isContainerBlock() const;
	virtual bool isCraftingBlock() const;
	virtual bool isInteractiveBlock() const;
	virtual bool isWaterBlocking() const;
	virtual bool isHurtableBlock() const;
	virtual bool isFenceBlock() const;
	virtual bool isStairBlock() const;
	virtual bool isRailBlock() const;
	virtual bool canHurtAndBreakItem() const;
	virtual bool isSignalSource() const;
	virtual bool isValidAuxValue(int) const;
	virtual int getDirectSignal(BlockSource&, const BlockPos&, int) const;
	virtual bool waterSpreadCausesSpawn() const;
	virtual bool shouldConnectToRedstone(BlockSource&, const BlockPos&, int) const;
	virtual void handleRain(BlockSource&, const BlockPos&, float) const;
	virtual float getThickness() const;
	virtual bool checkIsPathable(Entity&, const BlockPos&, const BlockPos&) const;
	virtual void dispense(BlockSource&, Container&, int, const Vec3&, signed char) const;
	virtual void onPlace(BlockSource&, const BlockPos&) const;
	virtual void onRemove(BlockSource&, const BlockPos&) const;
	virtual void onExploded(BlockSource&, const BlockPos&, Entity*) const;
	virtual void onStepOn(Entity&, const BlockPos&) const;
	virtual void onFallOn(BlockSource&, const BlockPos&, Entity*, float) const;
	virtual void transformOnFall(BlockSource&, const BlockPos&, Entity*, float) const;
	virtual void onRedstoneUpdate(BlockSource&, const BlockPos&, int, bool) const;
	virtual void onMove(BlockSource&, const BlockPos&, const BlockPos&) const;
	virtual bool detachesOnPistonMove(BlockSource&, const BlockPos&) const;
	virtual void onLoaded(BlockSource&, const BlockPos&) const;
	virtual int getRedstoneProperty(BlockSource&, const BlockPos&) const;
	virtual void updateEntityAfterFallOn(Entity&) const;
	virtual void onFertilized(BlockSource&, const BlockPos&, Entity*) const;
	virtual bool mayConsumeFertilizer(BlockSource&) const;
	virtual bool mayPick() const;
	virtual bool mayPick(BlockSource&, int, bool) const;
	virtual bool mayPlace(BlockSource&, const BlockPos&, signed char) const;
	virtual bool mayPlace(BlockSource&, const BlockPos&) const;
	virtual bool mayPlaceOn(Block const&) const;
	virtual bool tryToPlace(BlockSource&, const BlockPos&, unsigned char) const;
	virtual bool breaksFallingBlocks(int) const;
	virtual void destroy(BlockSource&, const BlockPos&, int, Entity*) const;
	virtual void playerWillDestroy(Player&, const BlockPos&, int) const;
	virtual bool getIgnoresDestroyPermissions(Entity&, const BlockPos&) const;
	virtual void neighborChanged(BlockSource&, const BlockPos&, const BlockPos&) const;
	virtual const AABB& getSecondPart(BlockSource&, const BlockPos&, BlockPos&) const;
	virtual short getResource(Random&, int, int) const;
	virtual int getResourceCount(Random&, int, int) const;
	virtual ItemInstance asItemInstance(BlockSource&, const BlockPos&, int) const;
	virtual bool spawnResources(BlockSource&, const BlockPos&, int, float, int) const;
	virtual bool spawnBurnResources(BlockSource&, float, float, float);
	virtual float getExplosionResistance(Entity*) const;
	virtual void clip(BlockSource&, const BlockPos&, Vec3 const&, Vec3 const&, bool, int) const;
	virtual bool use(Player&, const BlockPos&) const;
	virtual int getPlacementDataValue(Entity&, const BlockPos&, signed char, Vec3 const&, int) const;
	virtual void calcVariant(BlockSource&, const BlockPos&, unsigned char) const;
	virtual bool isAttachedTo(BlockSource&, const BlockPos&, BlockPos&) const;
	virtual void attack(Player*, const BlockPos&) const;
	virtual void handleEntityInside(BlockSource&, const BlockPos&, Entity*, Vec3&) const;
	virtual bool entityInside(BlockSource&, const BlockPos&, Entity&) const;
	virtual void playerDestroy(Player*, const BlockPos&, int) const;
	virtual bool canSurvive(BlockSource&, const BlockPos&) const;
	virtual int getExperienceDrop(Random&) const;
	virtual bool canBeBuiltOver(BlockSource&, const BlockPos&) const;
	virtual void triggerEvent(BlockSource&, const BlockPos&, int, int) const;
	virtual void getMobToSpawn(BlockSource&, const BlockPos&) const;
	virtual Color getMapColor(BlockSource&, const BlockPos&) const;
	virtual Color getMapColor() const;
	virtual bool shouldStopFalling(Entity&) const;
	virtual int calcGroundFriction(Mob&, const BlockPos&) const;
	virtual bool canHaveExtraData() const;
	virtual bool hasComparatorSignal() const;
	virtual int getComparatorSignal(BlockSource&, const BlockPos&, signed char, int) const;
	virtual bool shouldRenderFace(BlockSource&, const BlockPos&, signed char, AABB const&) const;
	virtual int getIconYOffset() const;
	virtual std::string buildDescriptionName(unsigned char) const;
	virtual int getColor(int) const;
	virtual int getColor(BlockSource&, const BlockPos&) const;
	virtual int getColor(BlockSource&, const BlockPos&, unsigned char) const;
	virtual int getColorForParticle(BlockSource&, const BlockPos&, int) const;
	virtual bool isSeasonTinted(BlockSource&, const BlockPos&) const;
	virtual void onGraphicsModeChanged(bool, bool, bool);
	virtual int getRenderLayer(BlockSource&, const BlockPos&) const;
	virtual int getExtraRenderLayers() const;
	virtual const AABB& getVisualShape(BlockSource&, const BlockPos&, AABB&, bool) const;
	virtual const AABB& getVisualShape(unsigned char, AABB&, bool) const;
	virtual int getVariant(int) const;
	virtual signed char getMappedFace(signed char, int) const;
	virtual bool animateTick(BlockSource&, const BlockPos&, Random&) const;
	virtual Block* init();
	virtual bool canBeSilkTouched() const;
	virtual ItemInstance getSilkTouchItemInstance(unsigned char) const;
	virtual Block* setVisualShape(AABB const&);
	virtual Block* setVisualShape(Vec3 const&, Vec3 const&);
	virtual Block* setLightBlock(Brightness);
	virtual Block* setLightEmission(float);
	virtual Block* setExplodeable(float);
	virtual Block* setDestroyTime(float);
	virtual Block* setFriction(float);
	virtual Block* setBlockProperty(BlockProperty);
	virtual Block* setTicking(bool);
	virtual Block* setMapColor(Color const&);
	virtual Block* addProperty(BlockProperty);
	virtual Block* addBlockState(BlockState::BlockStates, int);
	virtual Block* resetBitsUsed();
	virtual Block* setAllowsRunes(bool);
	virtual int getSpawnResourcesAuxValue(unsigned char) const;
	
	const std::string& getDescriptionId() const;
	void addAABB(const AABB&, const AABB*, std::vector<AABB, std::allocator<AABB>>&)const;
	void addAABB(const AABB&);
	void popResource(BlockSource&, const BlockPos&, const ItemInstance&) const;
	Block* setCategory(CreativeItemCategory);
	CreativeItemCategory getCreativeCategory() const;
	void setSolid(bool);
	bool isSolid() const;
	bool hasProperty(BlockProperty) const;
	float getFriction() const;
	Material& getMaterial() const;
	Block* lookupByName(const std::string&, bool);
	
	static std::unordered_map<std::string, const Block*> mBlockLookupMap;
	static std::vector<std::unique_ptr<Block>> mOwnedBlocks;
	static Block* mBlocks[256];
	static bool mSolid[256];
	static float mTranslucency[256];
	static uint8_t mLightBlock[256];
	static int mLightEmission[256];
	static bool mShouldTick[256];

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
	static Block* mStickyPiston; // 29
	static Block* mWeb; // 30
	static Block* mTallgrass; // 31
	static Block* mDeadBush; // 32
	static Block* mPiston; // 33
	static Block* mPistonArm; // 34
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
	static Block* mObserver; // 251
	static Block* mInfoReserved6; // 255
};

template <typename BlockType, typename...Args>
BlockType& registerBlock(const std::string &name, int id, const Args&...rest)
{
	const std::string block_name = Util::toLower(name);
	if (Block::mBlockLookupMap.count(block_name) != 0)
		return *(BlockType*)Block::mBlocks[id];

	BlockType* new_instance = new BlockType(name, id, rest...);
	Block::mBlocks[id] = new_instance;
	Block::mOwnedBlocks.emplace_back(std::unique_ptr<BlockType>(new_instance));
	Block::mBlockLookupMap.emplace(block_name, (const Block*)new_instance);
	return *new_instance;
}
