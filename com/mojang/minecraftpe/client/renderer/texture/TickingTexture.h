#pragma once
#include "TextureUVCoordinateSet.h"
class TextureGroup;

class TickingTexture {
protected:
	TextureUVCoordinateSet atlasTemplate; // 4
	int replicateValue; // 32
	char* frameBuffer; // 36
	int totalPixels; // 40
	char filler[16]; // 44

public:
	TickingTexture(const TextureUVCoordinateSet&, int);

	virtual ~TickingTexture();
	virtual void tick() = 0;
	virtual void bindTexture(TextureGroup&);
};
