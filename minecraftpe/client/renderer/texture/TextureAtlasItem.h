#pragma once
#include <string>
#include <vector>
class TextureUVCoordinateSet;

// 0.15.6
class TextureAtlasItem {
public:
	std::string name;
	std::vector<TextureUVCoordinateSet> textures;
	
	TextureAtlasItem(const std::string&, unsigned int);
};

