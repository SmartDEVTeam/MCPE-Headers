#pragma once

#include <string>
#include <vector>
#include <memory>
#include <unordered_map>

#include "../../../world/level/block/Block.h"
#include "../texture/TextureUVCoordinateSet.h"
#include "../texture/TextureAtlasItem.h"
#include "../../../util/Color.h"

namespace Json { class Value; }

// Size: 324
// 0.15.6
class BlockGraphics {
public:
	class SoundType {
	public:
		float volume; // 0
		float pitch; // 4
		std::string stepSound; // 8
		std::string breakSound; // 12
		std::string placeSound; // 16

		SoundType(const std::string&, float, float);
		SoundType(const std::string&, const std::string&, float, float);
		SoundType(const std::string&, const std::string&, const std::string&, float, float);

		~SoundType();

		float getVolume() const;
		float getPitch() const;
		std::string getStepSound() const;
		std::string getBreakSound() const;
		std::string getPlaceSound() const;
	};
	
	unsigned char blockId; // 4
	Block& block; // 8
	int textureIsotropic; // 12
	const SoundType& soundType; // 16
	int filler;
	BlockShape blockShape; // 24
	char filler2[8]; // 28
	Color mapColor; // 36
	AABB hitbox; // 56
	std::string bottomTexItem; // 84
	std::vector<TextureUVCoordinateSet> bottomTextures; // 88
	std::string topTexItem; // 100
	std::vector<TextureUVCoordinateSet> topTextures; // 104
	std::string northTexItem; // 116
	std::vector<TextureUVCoordinateSet> northTextures; // 120
	std::string southTexItem; // 132
	std::vector<TextureUVCoordinateSet> southTextures; // 136
	std::string westTexItem; // 148
	std::vector<TextureUVCoordinateSet> westTextures; // 152
	std::string eastTexItem; // 164
	std::vector<TextureUVCoordinateSet> eastTextures; // 168
	std::string bottomCarriedTexItem; // 180
	std::vector<TextureUVCoordinateSet> bottomCarriedTextures; // 184
	std::string topCarriedTexItem; // 196
	std::vector<TextureUVCoordinateSet> topCarriedTextures; // 200
	std::string northCarriedTexItem; // 212
	std::vector<TextureUVCoordinateSet> northCarriedTextures; // 216
	std::string southCarriedTexItem; // 228
	std::vector<TextureUVCoordinateSet> southCarriedTextures; // 232
	std::string westCarriedTexItem; // 244
	std::vector<TextureUVCoordinateSet> westCarriedTextures; // 248
	std::string eastCarriedTexItem; // 260
	std::vector<TextureUVCoordinateSet> eastCarriedTextures; // 264
	std::string bottomTexName; // 276
	std::string topTexName; // 280
	std::string northTexName; // 284
	std::string southTexName; // 288
	std::string westTexName; // 292
	std::string eastTexName; // 296
	std::string bottomCarriedTexName; // 300
	std::string topCarriedTexName; // 304
	std::string northCarriedTexName; // 308
	std::string southCarriedTexName; // 312
	std::string westCarriedTexName; // 316
	std::string eastCarriedTexName; // 320
	

	static std::unordered_map<std::string, BlockGraphics*> mBlockLookupMap;
	static BlockGraphics* mBlocks[256];
	static std::vector<std::unique_ptr<BlockGraphics>> mOwnedBlocks;
	static TextureAtlas* mTerrainTextureAtlas;
	
	static const BlockGraphics::SoundType SOUND_ANVIL;
	static const BlockGraphics::SoundType SOUND_CLOTH;
	static const BlockGraphics::SoundType SOUND_GLASS;
	static const BlockGraphics::SoundType SOUND_GRASS;
	static const BlockGraphics::SoundType SOUND_GRAVEL;
	static const BlockGraphics::SoundType SOUND_LADDER;
	static const BlockGraphics::SoundType SOUND_METAL;
	static const BlockGraphics::SoundType SOUND_NORMAL;
	static const BlockGraphics::SoundType SOUND_SAND;
	static const BlockGraphics::SoundType SOUND_SILENT;
	static const BlockGraphics::SoundType SOUND_SLIME;
	static const BlockGraphics::SoundType SOUND_SNOW;
	static const BlockGraphics::SoundType SOUND_STONE;
	static const BlockGraphics::SoundType SOUND_WOOD;

	BlockGraphics(const std::string&);

	virtual ~BlockGraphics();
	virtual bool shouldRenderFace(BlockSource&, const BlockPos&, signed char, const AABB&) const;
	virtual int getIconYOffset() const;
	virtual int getColor(int) const;
	virtual int getColor(BlockSource&, const BlockPos&) const;
	virtual int getColorForParticle(BlockSource&, const BlockPos&, int) const;
	virtual bool isSeasonTinted(BlockSource&, const BlockPos&) const;
	virtual void prepareRender(BlockSource&, const BlockPos&);
	virtual void onGraphicsModeChanged(bool, bool);
	virtual int getRenderLayer(BlockSource&, const BlockPos&) const;
	virtual int getExtraRenderLayers();
	virtual const AABB& getVisualShape(BlockSource&, const BlockPos&, AABB&, bool);
	virtual const AABB& getVisualShape(unsigned char, AABB&, bool);
	virtual const TextureUVCoordinateSet& getCarriedTexture(signed char, int) const;
	virtual bool animateTick(BlockSource&, const BlockPos&, Random&);
	virtual void randomlyModifyPosition(const BlockPos&, int&) const;
	virtual void randomlyModifyPosition(const BlockPos&) const;
	virtual void setVisualShape(const AABB&);
	virtual void setVisualShape(const Vec3&, const Vec3&);

	Block& getBlock() const;
	BlockShape getBlockShape() const;
	void getFaceTextureIsotropic();
	Color getMapColor(const FullBlock) const;
	Color getMapColor() const;
	int getRenderLayer() const;
	SoundType& getSoundType();
	const TextureUVCoordinateSet& getTexture(signed char) const;
	const TextureUVCoordinateSet& getTexture(signed char, int) const;
	bool isAlphaTested();
	bool isFullAndOpaque();
	void lookupByName(const std::string&, bool);
	void reloadBlockUVs(TextureAtlas&);
	BlockGraphics* setAllFacesIsotropic();
	BlockGraphics* setBlockShape(BlockShape);
	BlockGraphics* setCarriedTextureItem(const std::string&);
	BlockGraphics* setCarriedTextureItem(const std::string&, const std::string&, const std::string&);
	BlockGraphics* setMapColor(const Color&);
	BlockGraphics* setSoundType(const SoundType&);
	BlockGraphics* setTextureIsotropic(unsigned int);
	BlockGraphics* setTextureItem(const std::string&);
	BlockGraphics* setTextureItem(const std::string&, const std::string&, const std::string&);
	BlockGraphics* setTextureItem(const std::string&, const std::string&, const std::string&, const std::string&, const std::string&, const std::string&);
	
	static void initBlocks();
	static void teardownBlocks();	
	static bool isFullAndOpaque(const Block&);
	static void setTextureAtlas(std::shared_ptr<TextureAtlas>);
	static void setTextureIsotropic(BlockGraphics&, const Json::Value&);
	static void setTextures(BlockGraphics&, const Json::Value&);
	static void setCarriedTextures(BlockGraphics&, const Json::Value&);
	static void setBlockShape(BlockGraphics&, const Json::Value&);
	static TextureUVCoordinateSet getTextureUVCoordinateSet(const std::string&, int);
	static TextureAtlasItem getTextureItem(const std::string&);
};
