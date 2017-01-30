#pragma once

struct CompoundTag;
struct Packet;
struct MoveEntityPacketData;
class ChunkSource;
class Level;
class CircuitSystem;
class Seasons;
class Weather;

#include "DimensionId.h"
#include "GeneratorType.h"
#include "../../util/Color.h"

#include "../LevelListener.h"

// For MCPE 1.0.2.1
// Size: 298
class Dimension : public LevelListener
{
	char filler[8]; // 4
	int fogColor; // 12
	Level& level; // 16
	char filler1[12]; // 20
	float brightnessRamp; // 32
	char filler2[80]
	DimensionId id; // 116
	bool ultraWarm; // 120
	bool ceiling; // 121
	bool isDay; // 123
	short idk; // 124
	char filler3[66]; // 126
	ChunkSource* chunkSource; // 192
	Weather* weather; // 196
	Seasons* seasons; // 200
	CircuitSystem* circuitSystem; // 204


	Dimension(Level&, DimensionId, short);

	Color getSkyColor(const Entity&, float);

	std::unique_ptr<ChunkSource> _createGenerator(GeneratorType);
	static std::unique_ptr<Dimension> createNew(DimensionId, Level&);

	virtual ~Dimension();
	virtual void onBlockChanged(BlockSource&, const BlockPos&, FullBlock, FullBlock, int, Entity*);
	virtual void onBlockEvent(BlockSource&, int, int, int, int, int);
	virtual void onNewChunkFor(Player&, LevelChunk&);
	virtual Dimension* init();
	virtual bool tick();
	virtual void tickRedstone();
	virtual void updateLightRamp();
	virtual bool isNaturalDimension() const;
	virtual bool isValidSpawn(int, int) const;
	virtual void getFogColor(float) const;
	virtual void getFogDistanceScale() const;
	virtual bool isFoggyAt(int, int) const;
	virtual void getCloudHeight() const;
	virtual bool mayRespawn() const;
	virtual bool hasGround() const;
	virtual void getSpawnPos() const;
	virtual void getSpawnYPosition() const;
	virtual bool hasBedrockFog();
	virtual void getClearColorScale();
	virtual std::string getName() const = 0;
	virtual void showSky() const;
	virtual bool isDay() const;
	virtual void translatePosAcrossDimension(const Vec3&, DimensionId) const;
	virtual void load(const CompoundTag&);
	virtual void save(CompoundTag&);
	virtual void sendBroadcast(const Packet&, Player*);
	virtual void getTimeOfDay(int, float) const;

	unsigned int setBrightnessRamp(unsigned int, float);
	void setUltraWarm(bool);
	void setCeiling(bool);
	DimensionId getId() const;
	Level& getLevel() const;
	const Level& getLevelConst() const;
	ChunkSource* getChunkSource() const;
	CircuitSystem* getCircuitSystem() const;
	bool isDay() const;
	bool isNaturalDimension() const;
	bool isFoggyAt(int, int) const;
	bool isRedstoneTick() const;
	bool hasGround() const;
	bool hasCeiling() const;
	bool hasBedrockFog() const;
};
