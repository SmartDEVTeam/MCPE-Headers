#pragma once

#include <string>

#include "../ResourceLocation.h"

// size: 28
// 0.15.6
class TextureUVCoordinateSet {
	float minU; // 0
	float minV; // 4
	float maxU; // 8
	float maxV; // 12
	unsigned short width; // 16
	unsigned short height; // 18
	ResourceLocation file; // 20

public:
	TextureUVCoordinateSet();
	TextureUVCoordinateSet(float, float, float, float, unsigned short, unsigned short, ResourceLocation);

	
	float offset(float) const;
	float offsetHeight(float, float) const;
	float offsetHeightPixel(float, float) const;
	float offsetWidth(float, float) const;
	float offsetWidthPixel(float, float) const;
	float subTexture(float, float, int, int) const;
	float inverseOffsetHeight(float, float) const;
	float inverseOffsetWidth(float, float) const;
	void fromOldSystem(int);
};
