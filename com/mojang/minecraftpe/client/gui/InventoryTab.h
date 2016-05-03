#pragma once

#include "ImageButton.h"

class NinePatchLayer;

class InventoryTab : public ImageButton {
public:
	NinePatchLayer* layer1;
	bool isRight;

	InventoryTab(int, const std::string&, NinePatchLayer*, bool);
	virtual void renderBg(MinecraftClient*, int, int);
	virtual bool isSecondImage(bool);
};