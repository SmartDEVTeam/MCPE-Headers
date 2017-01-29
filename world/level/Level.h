#pragma once

#include <memory>
#include "../material/Material.h"
#include "BlockSourceListener.h"

class AABB;
class Entity;
class Player;
class SoundPlayer;
class LevelSettings;
class MinecraftEventing;
class StructureManager;
class Random;
class EntityDamageSource;
class Difficulty;
class LightLayer;
class LevelChunk;
class EntityUniqueID;
class ResourcePackManager;
class LevelStorage;

class Level : public BlockSourceListener
{
public:
	Level(SoundPlayer&, std::unique_ptr<LevelStorage, std::default_delete<LevelStorage>>, const std::string&, const LevelSettings&, bool, MinecraftEventing&, ResourcePackManager&, StructureManager&);

	virtual ~Level();
	virtual void onSourceCreated(BlockSource&);
	virtual void onSourceDestroyed(BlockSource&);
	virtual void addEntity(BlockSource&, std::unique_ptr<Entity, std::default_delete<Entity>>);
	virtual void addGlobalEntity(BlockSource&, std::unique_ptr<Entity, std::default_delete<Entity>>);
	virtual void addAutonomousEntity(BlockSource&, std::unique_ptr<Entity, std::default_delete<Entity>>);
	virtual void addPlayer(std::unique_ptr<Player, std::default_delete<Player>>);
	virtual void takeEntity(EntityUniqueID);
	virtual void borrowEntity(EntityUniqueID, LevelChunk*);
	virtual void onPlayerDeath(Player&, const EntityDamageSource&);
	virtual void tick();
	virtual void directTickEntities(BlockSource&);
	virtual void updateSleepingPlayerList();
	virtual void setDifficulty(Difficulty);
	virtual void setCommandsEnabled(bool);
	virtual void runLightUpdates(BlockSource&, const LightLayer&, const BlockPos&, const BlockPos&);
	virtual void onNewChunkFor(Player&, LevelChunk&);
	virtual void onChunkLoaded(LevelChunk&);
	virtual void queueEntityRemoval(std::unique_ptr<Entity, std::default_delete<Entity>>&&, bool);
	virtual void removeEntityReferences(Entity&, bool);
	virtual void onAppSuspended();
	virtual ResourcePackManager getClientResourcePackManager();
	virtual ResourcePackManager getServerResourcePackManager();
	
	bool checkAndHandleWater(const AABB&, MaterialType, Entity*);
	Random* getRandom();
	int getSeaLevel();
	void setTime(int);
};
