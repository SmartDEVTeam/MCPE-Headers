#pragma once
#include <memory>
#include <string>
class TickingTexture;
class TextureData;

class TextureGroup {
public:
	void addTickingTexture(std::unique_ptr<TickingTexture>);
	TextureData& getTextureData(const std::string&);
};
