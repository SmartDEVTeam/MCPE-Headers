#pragma once

class LevelChunk;
class Player;
class Entity;
class LevelListener{
public:
~LevelListener();

virtual void onEntityRemoved(Entity&);
virtual void onEntityAdded(Entity&);
virtual void onNewChunkFor(Player&, LevelChunk&);
};