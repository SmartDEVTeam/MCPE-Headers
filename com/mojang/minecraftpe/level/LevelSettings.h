#pragma once

#include <string>

class LevelSettings {
public:
    unsigned int seed;  
	int gameType;  
	int generator;  
	int dayCycle;
public:
    LevelSettings();
	
    void* getDefaultSpawn() const;
	int getGameType() const;
	int getGenerator() const;
	unsigned int getSeed() const;
	int hasBeenLoadedInCreative() const;
};
