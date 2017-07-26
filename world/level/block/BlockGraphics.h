#pragma once

#include <unordered_map>
#include <memory>

class BlockSource;
class BlockPos;
class Block;
struct Vec3;
class Random;
class FullBlock;
enum class BlockRenderLayer;
enum class BlockShape;
class TextureAtlas;
class TextureAtlasItem;
class ResourcePackManager;
namespace Json { class Value; }

#include "../../../util/Color.h"
#include "../../phys/AABB.h"
#include "../../../client/render/TextureAtlasItem.h"

enum class BlockSoundType
{
    NORMAL, GRAVEL, WOOD, GRASS, METAL, STONE, CLOTH, GLASS, SAND, SNOW, LADDER, ANVIL, SLIME, SILENT, DEFAULT, UNDEFINED
};

class BlockGraphics
{
public:
	unsigned char blockId; // 4
	Block* block; // 8
	unsigned int isotropicTextureFace; // 12
	int filler1; // 16
	BlockShape blockShape; // 20
	bool unknown; // 24
	char filler2[3]; // 25
	float brightnessGamma; // 28
	Color mapColor1; // 32
	Color mapColor2; // 36
	Color mapColor3; // 40
	Color mapColor4; // 44
	int filler3; // 48
	BlockSoundType soundType; // 52
	AABB visualShape; // 56
	int filler4[6];
	TextureAtlasItem texture[6]; // 84
	TextureAtlasItem carriedTexture[6]; // 204
	std::string textureName[6]; // 324
	std::string carriedTextureName[6]; // 348

	BlockGraphics(std::string const&);

    // virtual
    virtual ~BlockGraphics();
    virtual bool shouldRenderFace(BlockSource&, BlockPos const&, signed char, AABB const&) const;
    virtual int getIconYOffset() const;
    virtual unsigned int getColor(int) const;
    virtual unsigned int getColor(BlockSource&, BlockPos const&) const;
    virtual unsigned int getColorForParticle(BlockSource&, BlockPos const&, int) const;
    virtual bool isSeasonTinted(BlockSource&, BlockPos const&) const;
    virtual BlockGraphics* onGraphicsModeChanged(bool, bool);
    virtual BlockRenderLayer getRenderLayer(BlockSource&, BlockPos const&) const;
    virtual void* getExtraRenderLayers();
    virtual AABB const& getVisualShape(BlockSource&, BlockPos const&, AABB&, bool);
    virtual AABB const& getVisualShape(unsigned char, AABB&, bool);
    virtual void* getCarriedTexture(signed char, int) const;
    virtual void animateTick(BlockSource&, BlockPos const&, Random&);
    virtual Vec3 randomlyModifyPosition(BlockPos const&, int&) const;
    virtual Vec3 randomlyModifyPosition(BlockPos const&) const;
    virtual void setVisualShape(AABB const&);
    virtual void setVisualShape(Vec3 const&, Vec3 const&);

    // non virtual
    void setTextures(BlockGraphics&, Json::Value const&);
    void setTextureItem(std::string const&);
    void setTextureItem(std::string const&, std::string const&, std::string const&);
    void setTextureItem(std::string const&, std::string const&, std::string const&, std::string const&, std::string const&, std::string const&);
    void setCarriedTextures(BlockGraphics&, Json::Value const&);
    void setCarriedTextureItem(std::string const&);
    void setCarriedTextureItem(std::string const&, std::string const&, std::string const&);
    void setCarriedTextureItem(std::string const&, std::string const&, std::string const&, std::string const&, std::string const&, std::string const&);
    void setTextureIsotropic(BlockGraphics&, Json::Value const&);
    void setTextureIsotropic(unsigned int);
    void setAllFacesIsotropic();
    void setBlockShape(BlockGraphics&, Json::Value const&);
    void setBlockShape(BlockShape);
    void setBrightnessGamma(BlockGraphics&, Json::Value const&);
    void setSoundType(BlockGraphics&, Json::Value const&);
    void setSoundType(BlockSoundType);
    void setMapColor(Color const&);
    TextureAtlasItem* getTextureItem(std::string const&);
    Block* getBlock() const;
    Color getMapColor(FullBlock const&) const;
    Color getMapColor() const;
    TextureUVCoordinateSet& getTexture(signed char) const;
    TextureUVCoordinateSet& getTexture(signed char, int) const;
    TextureAtlasItem& getAtlasItem(signed char) const;
    bool isTextureIsotropic(signed char) const;
    bool isAlphaTested();
    bool isFullAndOpaque();
    bool isFullAndOpaque(Block const&);
    unsigned int getFaceTextureIsotropic();
    BlockSoundType getSoundType() const;
    BlockShape getBlockShape() const;
    BlockRenderLayer getRenderLayer() const;
    
    static void initBlocks(ResourcePackManager&);
    static void teardownBlocks();
    static void setTextureAtlas(std::shared_ptr<TextureAtlas>);
    static void reloadBlockUVs(TextureAtlas&);
    static TextureUVCoordinateSet getTextureUVCoordinateSet(std::string const&, int);
    static BlockGraphics* lookupByName(std::string const&, bool);

    // static fields
    static float SIZE_OFFSET;
    static std::shared_ptr<TextureAtlas> mTerrainTextureAtlas;
    static BlockGraphics* mBlocks[256];
    static std::vector<std::unique_ptr<BlockGraphics>> mOwnedBlocks;
    static std::unordered_map<std::string, BlockGraphics*> mBlockLookupMap;

};
