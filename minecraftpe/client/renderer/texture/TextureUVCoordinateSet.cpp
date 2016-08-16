#include "TextureUVCoordinateSet.h"

TextureUVCoordinateSet::TextureUVCoordinateSet(float minU, float minV, float maxU, float maxV, unsigned short width, unsigned short height) {
	setUV(minU, minV, maxU, maxV);
	this->width = width;
	this->height = height;
}

float TextureUVCoordinateSet::getMinU() {
	return minU;
}

float TextureUVCoordinateSet::getMinV() {
	return minV;
}

float TextureUVCoordinateSet::getMaxU() {
	return maxU;
}

float TextureUVCoordinateSet::getMaxV() {
	return maxV;
}

void TextureUVCoordinateSet::setUV(float minU, float minV, float maxU, float maxV) {
	this->minU = minU;
	this->maxU = maxU;
	this->minV = minV;
	this->maxV = maxV;
}

float TextureUVCoordinateSet::getInterpolatedU(float par1) {
	float var3 = maxU - minU;
	return minU + var3 * par1 / width;
}

float TextureUVCoordinateSet::getInterpolatedV(float par1) {
	float var3 = maxV - minV;
	return minV + var3 * par1 / height;
}