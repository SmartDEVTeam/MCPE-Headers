#pragma once

#include "Button.h"
#include "IntRectangle.h"
#include "../renderer/TexturePtr.h"

struct ImageDef {
	mce::TexturePtr texturePtr; // 0
	int x; // 12
	int y; // 16
	float width; // 20
	float height; // 24
	IntRectangle src; // 28
	bool hasSrc; // 44
};

class ImageButton : public Button {
public:
	ImageDef imageDef; // 108
	Color overlay; // 156
	bool scaleWhenPressed; // 172
	int yOffset; // 176

	ImageButton(int, const std::string&);
	ImageButton(int, const std::string&, ImageDef);
	virtual ~ImageButton();
	virtual void render(MinecraftClient*, int, int);
	virtual void renderBg(MinecraftClient*, int, int);
	virtual void setYOffset(int);
	virtual void setupDefault();
	virtual bool isSecondImage(bool);

	void setImageDef(ImageDef, bool);
};
