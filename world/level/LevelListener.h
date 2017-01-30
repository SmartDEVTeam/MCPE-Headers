#pragma once

#include <string>
#include "BlockSourceListener.h"

struct ParticleType;
struct Vec3;
struct EntityLocation;
class Player;
struct LevelChunk;
struct LevelEvent;
struct ImageData;

class LevelListener : public BlockSourceListener
{
	virtual ~LevelListener();
	virtual void allChanged();
	virtual void addParticle(ParticleType, const Vec3&, const Vec3&, int);
	virtual void playMusic(const std::string&, const Vec3&, float);
	virtual void playStreamingMusic(const std::string&, int, int, int);
	virtual void onEntityAdded(Entity&);
	virtual void onEntityRemoved(Entity&);
	virtual void onNewChunkFor(Player&, LevelChunk&);
	virtual void onChunkLoaded(LevelChunk&);
	virtual void onChunkUnloaded(LevelChunk&);
	virtual void levelEvent(LevelEvent, const Vec3&, int);
	virtual void levelSoundEvent(LevelSoundEvent, const Vec3&, int, EntityType, bool, bool);
	virtual void takePicture(TextureData&, Entity*, Entity*, bool, const std::string&);
	virtual void playerListChanged();
};
