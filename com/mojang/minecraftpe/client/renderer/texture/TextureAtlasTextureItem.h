#pragma once
#include <string>
#include <vector>
class TextureUVCoordinateSet;

class TextureAtlasTextureItem {
public:
	std::string name;
	std::vector<TextureUVCoordinateSet> textures;
	int count;
	
	const TextureUVCoordinateSet& operator[](int) const;
};

