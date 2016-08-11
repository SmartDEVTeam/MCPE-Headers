#pragma once

#include "ImageButton.h"

class LargeImageButton : public ImageButton {
public:
	float idk; // 180

	LargeImageButton(int, const std::string&);
	LargeImageButton(int, const std::string&, ImageDef);
	virtual ~LargeImageButton();
	virtual void render(MinecraftClient*, int, int);
	virtual void setupDefault();
};