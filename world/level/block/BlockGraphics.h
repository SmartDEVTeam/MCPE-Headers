#pragma once

#include <unordered_map>
#include "../../../util/Color.h"
#include "../../phys/AABB.h"
#include "../../../client/render/TextureAtlasItem.h"
#include "BlockShape.h"

class BlockSource;
class BlockPos;
class Block;
class AABB;
class Vec3;
class Random;
class FullBlock;
struct BlockRenderLayer;
class TextureAtlas;
class TextureAtlasItem;
namespace Json { class Value; }

enum class BlockSoundType
{
    NORMAL, GRAVEL, WOOD, GRASS, METAL, STONE, CLOTH, GLASS, SAND, SNOW, LADDER, ANVIL, SLIME, SILENT, DEFAULT, UNDEFINED
};

class BlockGraphics
{
public:
    void**vtable;
	char filler[500];

	static std::shared_ptr<TextureAtlas> mTerrainTextureAtlas;
	static std::vector<std::unique_ptr<BlockGraphics>> mOwnedBlocks;
	static BlockGraphics* mBlocks[256];

	BlockGraphics(const std::string&);

	virtual ~BlockGraphics();

	bool shouldRenderFace(BlockSource&, const BlockPos&, signed char, const AABB&) const;
	int getIconYOffset() const;
	unsigned char getColor(int) const;
	unsigned char getColor(BlockSource&, const BlockPos&) const;
	unsigned char getColorForParticle(BlockSource&, const BlockPos&, int) const;
	bool isSeasonTinted(BlockSource&, const BlockPos&) const;
	void prepareRender(BlockSource&, const BlockPos&);
	void onGraphicsModeChanged(bool, bool);
	BlockRenderLayer getRenderLayer(BlockSource&, const BlockPos&) const;
	int getExtraRenderLayers();
	AABB& getVisualShape(BlockSource&, const BlockPos&, AABB&, bool);
	AABB& getVisualShape(unsigned char, AABB&, bool);
	TextureUVCoordinateSet& getCarriedTexture(signed char, int) const;
	bool animateTick(BlockSource&, const BlockPos&, Random&);
	Vec3& randomlyModifyPosition(const BlockPos&, int&) const;
	Vec3& randomlyModifyPosition(const BlockPos&) const;
	void setVisualShape(const AABB&);
	void setVisualShape(const Vec3&, const Vec3&);
	void setSoundType(BlockSoundType);
	Block& getBlock() const;
	BlockShape getBlockShape() const;
	void getFaceTextureIsotropic();
	Color getMapColor(const FullBlock) const;
	Color getMapColor() const;
	BlockRenderLayer getRenderLayer() const;
	BlockSoundType getSoundType();
	TextureUVCoordinateSet& getTexture(signed char) const;
	TextureUVCoordinateSet& getTexture(signed char, int) const;
	bool isAlphaTested();
	bool isFullAndOpaque(const Block&);
	bool isFullAndOpaque();
	void lookupByName(const std::string&, bool);
	void reloadBlockUVs(TextureAtlas&);
	void setAllFacesIsotropic();
	void setBlockShape(BlockGraphics&, const Json::Value&);
	void setBlockShape(BlockShape);
	void setCarriedTextureItem(const std::string&);
	void setCarriedTextureItem(const std::string&, const std::string&, const std::string&);
	void setCarriedTextures(BlockGraphics&, const Json::Value&);
	void setMapColor(const Color&);
	void setTextureAtlas(std::shared_ptr<TextureAtlas>);
	void setTextureIsotropic(BlockGraphics&, const Json::Value&);
	void setTextureIsotropic(unsigned int);
	void setTextureItem(const std::string&);
	void setTextureItem(const std::string&, const std::string&, const std::string&);
	void setTextureItem(const std::string&, const std::string&, const std::string&, const std::string&, const std::string&, const std::string&);
	void setTextures(BlockGraphics&, const Json::Value&);

	static void initBlocks();
	static void teardownBlocks();
	static TextureUVCoordinateSet getTextureUVCoordinateSet(const std::string&, int);
	static TextureAtlasItem getTextureItem(const std::string&);
};

