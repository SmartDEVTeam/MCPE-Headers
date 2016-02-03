#pragma once

class TextureUVCoordinateSet {
	float minU;
	float minV;
	float maxU;
	float maxV;
	unsigned short width;
	unsigned short height;
	int file;

public:
	TextureUVCoordinateSet();
	TextureUVCoordinateSet(float, float, float, float, unsigned short, unsigned short);

	float getMinU();
	float getMinV();
	float getMaxU();
	float getMaxV();
	void setUV(float, float, float, float);
	float getInterpolatedU(float);
	float getInterpolatedV(float);
};
