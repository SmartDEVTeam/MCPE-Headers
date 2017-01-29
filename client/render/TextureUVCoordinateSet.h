#pragma once

#include "ResourceLocation.h"

class TextureUVCoordinateSet
{
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
};

