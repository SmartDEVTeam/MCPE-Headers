#include "BlockHelper.h"

#include "Block.h"
#include "../../../json/JSONReadVerifier.h"
#include "../../../client/renderer/ResourceLocation.h"
#include "../../../client/renderer/Resource.h"
#include "../../../client/renderer/block/BlockGraphics.h"
#include "../../../util/Util.h"

std::vector<Block*> BlockHelper::blocks;

Block* BlockHelper::registerBlock(Block* block) {
	Block::mOwnedBlocks.push_back(std::unique_ptr<Block>(block));
	Block::mBlocks[block->blockId] = block;
	Block::mBlockLookupMap[Util::toLower(block->name)] = block;
	blocks.push_back(block);
	return block;
}

BlockGraphics* BlockHelper::registerBlockGraphics(const std::string& name, Json::Value& jvalue) {
	BlockGraphics* bg = new BlockGraphics(name);
	BlockGraphics::mOwnedBlocks.push_back(std::unique_ptr<BlockGraphics>(bg));
	BlockGraphics::mBlocks[bg->blockId] = bg;
	Json::Value subVal = Json::Value(jvalue[name]);
	BlockGraphics::setTextures(*bg, subVal["textures"]);
	BlockGraphics::setCarriedTextures(*bg, subVal["carried_textures"]);
	BlockGraphics::setTextureIsotropic(*bg, subVal["isotropic"]);
	BlockGraphics::setBlockShape(*bg, subVal["blockshape"]);
	return bg;
}

void BlockHelper::setupBlockGraphics() {
	Json::Value jvalue;
	Json::Reader jreader;
	std::string resource;
	Resource::load({"block.graphics.meta", "InUserPackage"}, resource);
	bool result = jreader.parse(resource, jvalue, true);
	JSONReadVerifier::verifyRead("blocks.json", jreader, result);
	for(Block* block : blocks) {
		registerBlockGraphics(Util::toLower(block->name), jvalue);
	}
}