#pragma once
#include <memory>
#include "../material/Material.h"
#include "BlockSourceListener.h"
class AABB;
class Entity;
class Player;
class Random;
class EntityDamageSource;
class Difficulty;
class LightLayer;
class LevelChunk;

class Level : public BlockSourceListener {
public:
	virtual ~Level();
	virtual void onSourceCreated(BlockSource&);
	virtual void onSourceDestroyed(BlockSource&);
	virtual void onBlockChanged(BlockSource&, const BlockPos&, FullBlock, FullBlock, int);
	virtual void addEntity(std::unique_ptr<Entity>);
	virtual void addPlayer(std::unique_ptr<Player>);
	virtual void addGlobalEntity(std::unique_ptr<Entity>);
	virtual void onPlayerDeath(Player&, const EntityDamageSource&);
	virtual void tick();
	virtual void directTickEntities(BlockSource&);
	virtual void updateSleepingPlayerList();
	virtual void setDefficulty(Difficulty);
	virtual void runLightUpdates(BlockSource&, const LightLayer&, const BlockPos&, const BlockPos&);
	virtual void onNewChunkFor(Player&, LevelChunk&);
	virtual void onChunkLoaded(LevelChunk&);
	virtual void removeEntity(std::unique_ptr<Entity>&&, bool);
	virtual void removeEntity(Entity&, bool);
	virtual void onAppSuspended();
	
	bool checkAndHandleWater(const AABB&, MaterialType, Entity*);
	Random* getRandom();
	int getSeaLevel();
	void setTime(int);
};

