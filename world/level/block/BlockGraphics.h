#pragma once

#include <string>
#include <vector>
#include <memory>

#include "Block.h"
#include "BlockShape.h"
#include "BlockSoundType.h"

class TextureAtlas;
class TextureAtlasTextureItem;
namespace Json { class Value; }

class BlockGraphics 
{
public:
	static std::shared_ptr<TextureAtlas> mTerrainTextureAtlas;
	static std::vector<std::unique_ptr<BlockGraphics>> mOwnedBlocks;
	static BlockGraphics* mBlocks[256];

	BlockGraphics(const std::string&);

	virtual ~BlockGraphics();
	virtual bool shouldRenderFace(BlockSource&, const BlockPos&, signed char, const AABB&) const;
	virtual void getIconYOffset() const;
	virtual void getColor(int) const;
	virtual void getColor(BlockSource&, const BlockPos&) const;
	virtual void getColorForParticle(BlockSource&, const BlockPos&, int) const;
	virtual bool isSeasonTinted(BlockSource&, const BlockPos&) const;
	virtual void onGraphicsModeChanged(bool, bool);
	virtual void getRenderLayer(BlockSource&, const BlockPos&) const;
	virtual void getExtraRenderLayers();
	virtual void getVisualShape(BlockSource&, const BlockPos&, AABB&, bool);
	virtual void getVisualShape(unsigned char, AABB&, bool);
	virtual void getCarriedTexture(signed char, int) const;
	virtual void animateTick(BlockSource&, const BlockPos&, Random&);
	virtual void randomlyModifyPosition(const BlockPos&, int&) const;
	virtual void randomlyModifyPosition(const BlockPos&) const;
	virtual void setVisualShape(const AABB&);
	virtual void setVisualShape(const Vec3&, const Vec3&);

	static void initBlocks();
	static void teardownBlocks();
	static TextureUVCoordinateSet getTextureUVCoordinateSet(const std::string&, int);
	static TextureAtlasTextureItem getTextureItem(const std::string&);
};
