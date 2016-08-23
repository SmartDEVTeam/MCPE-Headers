#pragma once

#include <string>

#include "../../../json/json.h"

class Block;
class BlockGraphics;

class BlockHelper {
public:
	static std::vector<Block*> blocks;

	static Block* registerBlock(Block*);
	static BlockGraphics* registerBlockGraphics(const std::string&, Json::Value&);
	static void setupBlockGraphics();
};