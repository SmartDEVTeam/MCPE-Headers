#pragma once

#include <string>
#include <memory>

#include "../LevelListener.h"
#include "DimensionId.h"
#include "../GeneratorType.h"
#include "../../util/Color.h"
class FullBlock;
class Level;
class BlockSource;
class BlockPos;
class Player;
class LevelChunk;
class CompoundTag;
class ChunkSource;
class Packet;
class MoveEntityPacketData;
class Entity;
class SaveData;

class Dimension : public LevelListener {
private:
	Level *level;
	DimensionId id;
	bool ultrawarm;
	bool ceiling;

public:
	static std::unique_ptr<Dimension> createNew(DimensionId, Level&);

	Dimension(Level&, DimensionId);

	std::unique_ptr<ChunkSource> _createGenerator(GeneratorType);

	virtual ~Dimension();
	virtual void onBlockChanged(BlockSource&, const BlockPos&, FullBlock, FullBlock, int);
	virtual void onBlockEvent(BlockSource&, int, int, int, int, int);
	virtual void onNewChunkFor(Player&, LevelChunk&);
	virtual void init();
	virtual void tick();
	virtual void updateLightRamp();
	virtual bool isNaturalDimension() const;
	virtual bool isValidSpawn(int, int) const;
	virtual Color getFogColor(float) const;
	virtual float getFogDistanceScale() const;
	virtual bool isFoggyAt(int, int) const;
	virtual float getCloudHeight() const;
	virtual bool mayRespawn() const;
	virtual bool hasGround() const;
	virtual void getSpawnYPosition();
	virtual bool hasBedrockFog();
	virtual float getClearColorScale();
	virtual std::string getName() const = 0;
	virtual void load(const CompoundTag&);
	virtual void save(CompoundTag&);
	virtual void sendDimensionPackets();
	virtual void sendBroadcast(const Packet&, Player*);
	virtual void addMoveEntityPacket(const MoveEntityPacketData&);
	virtual void addSetEntityMotionPacket(Entity&);
	virtual void getTimeOfDay(int, float) const;

	ChunkSource *getChunkSource() const;

	void setCeiling(bool value);
	void setUltraWarm(bool value);

	Level *getLevel() const;
	Level *getLevelCount() const;
	DimensionId getId() const;
	int getHeight() const;
	bool isDay() const;
};
