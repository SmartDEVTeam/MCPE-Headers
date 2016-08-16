#pragma once

#include "LargeImageButton.h"

class NinePatchLayer;

class ImageWithBackground : public LargeImageButton {
public:
	NinePatchLayer* layer1; // 184
	NinePatchLayer* layer2; // 188

	ImageWithBackground(int);
	virtual ~ImageWithBackground();
	virtual void render(MinecraftClient*, int, int);
	virtual void renderBg(MinecraftClient*, int, int);
	
	void setSize(float, float);
	void init(mce::TextureGroup*, int, int, IntRectangle, IntRectangle, int, int, const std::string&);
};