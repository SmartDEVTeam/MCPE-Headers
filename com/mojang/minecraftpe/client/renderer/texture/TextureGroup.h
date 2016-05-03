#pragma once
#include <memory>
#include <string>

#include "TextureLocation.h"

class TickingTexture;
class TextureData;


namespace mce {
class TexturePtr;

class TextureGroup {
public:
	void addTickingTexture(std::unique_ptr<TickingTexture>);
	TextureData& getTextureData(const std::string&);
	TexturePtr getTexture(const std::string&, TextureLocation);
};

};
