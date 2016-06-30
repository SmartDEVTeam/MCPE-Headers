#pragma once

#include <string>
#include <vector>
#include <memory>

#include "../../../world/level/block/Block.h"
#include "../../../util/Color.h"
class BlockSource;
struct BlockPos;
class AABB;
struct Vec3;
class Random;
class TextureAtlas;
namespace Json { class Value; }

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

	static std::shared_ptr<TextureAtlas> mTerrainTextureAtlas;
	static std::vector<std::unique_ptr<BlockGraphics>> mOwnedBlocks;
	static BlockGraphics* mBlocks[256];
	//static BlockGraphics* mBlockLookupMap; //HALP
	
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
	virtual void setSoundType(const BlockGraphics::SoundType&);

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
	static TextureAtlasTextureItem getTextureItem(const std::string&);
};
