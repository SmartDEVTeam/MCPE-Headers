#pragma once

#include "../AppPlatformListener.h"
#include "ScrollingPane.h"
class ItemRenderChunkType;
class ItemInstance;
class Tessellator;

namespace Touch {
	
class IInventoryPaneCallback;

class InventoryPane : public ScrollingPane, public AppPlatformListener {
	char filler [152520 - 788];
	// virtual methods
	InventoryPane(Touch::IInventoryPaneCallback*, MinecraftClient&, IntRectangle const&, int, float, int, int, int, bool, bool, bool);
	virtual ~InventoryPane();
	virtual void handleButtonPress(MinecraftClient*, short);
	virtual void renderBatch(std::vector<ScrollingPane::GridItem>&, float, float, float);
	virtual void onSelect(int, bool);
	virtual void refreshItems();
	virtual void onAppSuspended();
	virtual void onAppResumed();

	void drawRectangleOnSelectedItem(ScrollingPane::GridItem&);
	void onSelectItem();
	void setRenderDecorations(bool);
	void tick();
	void renderSelectedItem(std::vector<ScrollingPane::GridItem>, Tessellator&, ScrollingPane::GridItem*&, float&, float&);
	void setControllerDirection(StickDirection);
	void SetAdditionalMargin(int, int);
	void buildInventoryItemsChunk(std::vector<ItemInstance const*>&, ItemRenderChunkType);
};

class IInventoryPaneCallback {
	virtual ~IInventoryPaneCallback();
	virtual bool addItem(const Touch::InventoryPane*, int) = 0;
	virtual bool isAllowed(int) = 0;
	virtual std::vector<const ItemInstance*> getItems(const Touch::InventoryPane*) = 0;
};

};
