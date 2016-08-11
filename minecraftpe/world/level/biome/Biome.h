#pragma once

class BiomeDecorator;
class Random;
class EntityType;
class BlockSource;
class LevelChunk;
struct Color;
struct BlockPos;

class Biome {
public:
	enum class BiomeType : int {

	};

	Biome(int, Biome::BiomeType, std::unique_ptr<BiomeDecorator, std::default_delete<BiomeDecorator>>);

	virtual ~Biome();
	virtual Color setColor(int);
	virtual Color setColor(int, bool);
	virtual void getTreeFeature(Random*);
	virtual void getGrassFeature(Random*);
	virtual void getTemperature();
	virtual void adjustScale(float);
	virtual void adjustDepth(float);
	virtual Color getSkyColor(float);
	virtual void getMobs(EntityType);
	virtual int getCreatureProbability();
	virtual Color getFoliageColor();
	virtual void getRandomFlowerTypeAndData(Random&, const BlockPos&);
	virtual void decorate(BlockSource*, Random&, const BlockPos&, bool, float);
	virtual void buildSurfaceAt(Random&, LevelChunk&, const BlockPos&, float);
	virtual Color getGrassColor(const BlockPos&);
	virtual bool refreshbiome(unsigned int);
	virtual void getTemperatureCategory() const;
	virtual bool isSame(Biome*);
	virtual bool isHumid();
	virtual void createMutatedCopy(int);
};
