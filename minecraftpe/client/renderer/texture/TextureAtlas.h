#pragma once
#include <string>
class TextureAtlasTextureItem;

class TextureAtlas {
public:
	TextureAtlasTextureItem& getTextureItem(const std::string&) const;
};

