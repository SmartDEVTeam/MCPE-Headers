#pragma once

class Block;
class Material;
class BlockEntity;
class Level;
class Dimension;
class ChunkSource;
class LevelChunk;
enum class DimensionId;
enum class EntityType;
enum class MaterialType;
class Bounds;
class LightLayer;
class Biome;
class Brightness;
class AABB;
#include "BlockPos.h"
#include "FullBlock.h"

class BlockSource {
public:
	virtual ~BlockSource();
	
    BlockSource(Level&, Dimension&, ChunkSource&, bool, bool);
	
	const Level& getLevel() const;
    Level& getLevel();
    const Level& getLevelConst() const;
    ChunkSource& getChunkSource();
    bool getPublicSource() const;
    bool isOwnerThread() const;
    void clearCachedLastChunk();

    const Dimension& getDimension() const;
    Dimension& getDimension();
    DimensionId getDimensionId() const;
    const Dimension& getDimensionConst() const;
	
    LevelChunk* getChunk(ChunkPos const&);
    LevelChunk* getChunk(int, int);
    LevelChunk* getChunkAt(BlockPos const&);
    LevelChunk* getChunkAt(int, int, int);
    LevelChunk* getWritableChunk(ChunkPos const&);
    bool hasChunksAt(Bounds const&);
    bool hasChunksAt(AABB const&);
    bool hasChunksAt(BlockPos const&, int);
    bool hasChunksAt(int, int, int, int);
    bool hasChunksAt(BlockPos const&, BlockPos const&);

    Biome& getBiome(BlockPos const&);
    Biome* tryGetBiome(BlockPos const&);

    int getHeightmap(BlockPos const&);
    int getHeightmap(int, int);
    BlockPos getHeightmapPos(BlockPos const&);
    BlockID getTopBlock(int, int&, int);
    BlockPos getTopRainBlockPos(BlockPos const&);
    bool checkIsTopRainBlockPos(BlockPos const&);
    bool findNextTopSolidBlockUnder(BlockPos&);
    bool findNextSpawnBlockUnder(BlockPos&);
    int getAboveTopSolidBlock(BlockPos const&, bool, bool);
    int getAboveTopSolidBlock(int, int, bool, bool);
    int getAllocatedHeightAt(BlockPos const&);

    Block* getBlock(BlockPos const&);
    Block* getBlock(int, int, int);
    Material* getMaterial(BlockPos const&);
    Material* getMaterial(int, int, int);
    BlockID getBlockID(BlockPos const&);
    BlockID getBlockID(int, int, int);
    FullBlock getBlockAndData(BlockPos const&);
    FullBlock getBlockAndData(int, int, int);
    unsigned char getData(BlockPos const&);
    unsigned char getData(int, int, int);
    int getBrightness(LightLayer const&, BlockPos const&);
    int getBrightness(LightLayer const&, int, int, int);
    int getBrightness(BlockPos const&);
    int getBrightness(int, int, int);
    Brightness getRawBrightness(int, int, int, bool);
    Brightness getRawBrightness(BlockPos const&, bool);
    unsigned short getExtraData(BlockPos const&);
    BlockEntity* getBlockEntity(BlockPos const&);
    BlockEntity* getBlockEntity(int, int, int);
    int getGrassColor(BlockPos const&);
    bool hasBlock(BlockPos const&);
    bool hasBlock(int, int, int);
    bool isEmptyBlock(BlockPos const&);
    bool isEmptyBlock(int, int, int);
    bool isSolidBlockingBlock(int, int, int);
    bool isSolidBlockingBlock(BlockPos const&);
    bool isConsideredSolidBlock(int, int, int);
    bool isConsideredSolidBlock(BlockPos const&);
    bool isInWall(Vec3 const&);
    bool _isWaterAt(BlockPos const&);
    bool _isIceAt(BlockPos const&);
    bool isPositionUnderLiquid(BlockPos const&, MaterialType);
    bool isHumidAt(BlockPos const&);
	bool isSnowTemperature(BlockPos const&);
    bool shouldFreezeIgnoreNeighbors(BlockPos const&);
    bool shouldFreeze(BlockPos const&, bool);
    bool shouldThaw(BlockPos const&, bool);
	
	void setBlock(int, int, int, BlockID, int);
    void setBlockAndData(BlockPos const&, FullBlock, int, Entity*);
    void setBlock(BlockPos const&, BlockID, int);
    void setBlockAndData(BlockPos const&, FullBlock, int, Entity*, std::unique_ptr<BlockEntity, std::default_delete<BlockEntity>>);
    void setBlockAndData(BlockPos const&, BlockID, unsigned char, int, Entity*);
    void setBlockAndData(int, int, int, BlockID, unsigned char, int);
    void setBlockAndData(int, int, int, FullBlock, int);
    void setBlockNoUpdate(int, int, int, BlockID);
    void setBlockAndDataNoUpdate(int, int, int, FullBlock);
    void setBrightness(LightLayer const&, BlockPos const&, Brightness);
    void setBrightness(LightLayer const&, int, int, int, Brightness);
    void* getLightColor(BlockPos const&, Brightness);
    void setExtraData(BlockPos const&, unsigned short);
    void setGrassColor(int, BlockPos const&, int);
    void setBorderBlock(BlockPos const&, bool);
    void removeBlock(int, int, int);
    void removeBlock(BlockPos const&);
    void removeBlockEntity(BlockPos const&);
};

