#pragma once

#include "texture/TextureUVCoordinateSet.h"
#include "../../world/phys/AABB.h"
#include "MaterialPtr.h"
#include "../../world/level/block/BlockShape.h"
#include "../../CommonTypes.h"

class Block;
class BlockSource;
class Tessellator;
class BlockPos;
class Vec3;

namespace mce {
	class TexturePtr;
};

class BlockTessellator {
public:
	bool forceOpaque; // 0
	bool otherb; // 1
	BlockSource* blockSource; // 4
	TextureUVCoordinateSet forcedUV; // 8
	bool useForcedUV; // 36
	bool idk; // 37
	int renderLayer; // 40
	char filler[84]; // 44
	int rotBottom; // 128
	int rotTop; // 132
	int rotNorth; // 136
	int rotSouth; // 140
	int rotWest; // 144
	int rotEast; // 148
	char filler1[500]; // 152
	mce::MaterialPtr material; // 652
	Tessellator& tessellator; // 664
	AABB aabb; // 668

public:
	bool tessellateInWorld(Block&, const BlockPos&, bool);
	bool tessellateBlockInWorld(Block&, const BlockPos&);
	void renderGuiBlock(const FullBlock&, const mce::TexturePtr&, float, float);
	
	void renderNorth(Block&, const Vec3&, const TextureUVCoordinateSet&);
	void renderEast(Block&, const Vec3&, const TextureUVCoordinateSet&);
	void renderSouth(Block&, const Vec3&, const TextureUVCoordinateSet&);
	void renderWest(Block&, const Vec3&, const TextureUVCoordinateSet&);
	void renderFaceDown(Block&, const Vec3&, const TextureUVCoordinateSet&);
	void renderFaceUp(Block&, const Vec3&, const TextureUVCoordinateSet&);
	
	bool canRender(BlockShape);
	unsigned int getLightColor(const BlockPos&);
	DataID getData(const BlockPos&) const;
	BlockSource& getRegion() const;
	void setRegion(BlockSource&);
	int getRenderLayer() const;
	void setRenderLayer(int);
	void setForceOpaque(bool);
	void tex1(unsigned int);
	void blend(int, int, int, int);
	
	void setRenderBounds(float, float, float, float, float, float);
};
