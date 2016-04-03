#pragma once

#include <memory>

class BlockSource;
class Random;
class BlockPos;
class Feature;
class Biome;
class ClayFeature;
class SandFeature;
class OreFeature;
class FlowerFeature;
class HugeMushroomFeature;
class SpringFeature;
class TreeFeature;
class SpruceFeature;
class BirchFeature;
class RoofTreeFeature;
class PineFeature;
class MegaPineTreeFeature;
class TallGrassFeature;
class FancyTreeFeature;
class BlockBlobFeature;
class SwampTreeFeature;
class IcePatchFeature;
class JungleTreeFeature;
class MegaJungleTreeFeature;
class SavannaTreeFeature;
class CactusFeature;
class DoublePlantFeature;

class BiomeDecorator {
public:
	ClayFeature* clay; // 4
	SandFeature* sand; // 8
	SandFeature* gravelSurface; // 12
	OreFeature* dirtOre; // 16
	OreFeature* gravelOre; // 20
	OreFeature* stoneOre1; // 24
	OreFeature* stoneOre2; // 28
	OreFeature* stoneOre3; // 32
	OreFeature* coal; // 36
	OreFeature* iron; // 40
	OreFeature* gold; // 44
	OreFeature* redstone; // 48
	OreFeature* diamond; // 52
	OreFeature* lapis; // 56
	FlowerFeature* yellowFlower; // 60
	FlowerFeature* brownMushroom; // 64
	FlowerFeature* redMushroom; // 68
	HugeMushroomFeature* hugeMushroom; // 72
	// todo add the others here
	
public:	
	BiomeDecorator();
	virtual void decorateOres(BlockSource*, Random&, const BlockPos&);
	virtual ~BiomeDecorator();
	
	void _getRandomHeight(int, int, BlockSource*, Random&, const BlockPos&);
	void _getRandomSolidPosition(BlockSource*, const BlockPos&, Random&);
	void _getRandomSurfacePosition(BlockSource*, const BlockPos&, Random&);
	void _getRandomTreePosition(BlockSource*, const BlockPos&, Random&);
	bool _placeFeature(BlockSource*, const std::unique_ptr<Feature>&, const BlockPos&, Random&);
	void decorate(BlockSource*, Random&, Biome*, const BlockPos&, bool, float);
	void decorateDepthAverage(BlockSource*, Random&, const BlockPos&, int, std::unique_ptr<Feature>&, int, int);
	void decorateDepthSpan(BlockSource*, Random&, const BlockPos&, int, std::unique_ptr<Feature>&, int, int);
};