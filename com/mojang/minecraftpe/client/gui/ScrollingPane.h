#pragma once

#include "GuiElement.h"
#include "IntRectangle.h"
#include "../../world/phys/Vec3.h"
#include "../../world/phys/RectangleArea.h"

class ScrollBar {
	float x;
	float y;
	float w;
	float h;
	float scale;
	float alpha;

	ScrollBar();
	void render(MinecraftClient*, bool);
	void update(const IntRectangle&, float, int);
	void updateScale(float);
	void createMouseScrollBars();
};

class ScrollingPane : public GuiElement {
public:
	struct GridItem {
		int id;
		int x;
		int y;
		float xf;
		float yf;
		bool selected;
	};
	
	int flags;
	int columns;
	int rows;
	int numItems;
	int px;
	int py;
	float fpx;
	float fpy;
	float screenScale;
	float invScreenScale; // 88
	IntRectangle bbox;
	IntRectangle itemRect;
	IntRectangle itemBBox;
	RectangleArea area;
	RectangleArea bboxArea;
	

	ScrollingPane(int, const IntRectangle&, const IntRectangle&, int, int, float, const IntRectangle&);
	virtual ~ScrollingPane();
	virtual void renderBatch(std::vector<ScrollingPane::GridItem>&, float, float, float);
	virtual void renderItem(ScrollingPane::GridItem&, float);
	virtual void didEndDragging();
	virtual void didEndDecelerating();
	virtual void willBeginDecelerating();
	virtual void willBeginDragging();
	virtual void onSelect(int, bool);
	virtual void refreshItems();

	void addDeltaPos(float, float, float, int);
	void render(int, int, float, MinecraftClient*);
	void recalculateRows(int);
	void setNumItems(int);
	void UpdateHighlightItem(float, float);
	void _handleMouseInput(float, bool);
	void touchesBegan(float, float, int);
	void refreshPane();
	int getColumns();
	int getContentOffset();
	ScrollBar& getVerticleScrollBar();
	bool shouldRenderSelected();
	void setRenderSelected(bool);
	int getRows();
	int getNumItems();
	bool thereAreMoreItemsToDisplay(int, int, int);
	int getSelectedItemId();
	int _getAdditionalScrollBarWidth();
	int getAdditionalScrollBarWidth() const;
	bool thereAreMoreItemsToDisplay() const;
	void setScrollT(float);
	void calculateAndSetCurrentMouseScrollT();
	void handleMouseInput(float);
	void handleUserInput(bool);
	void updateScrollBoxSize(float);
	void updateScrollBarScale(int, int, int, int);
	GridItem* getGridItemFor_slow(int, ScrollingPane::GridItem&);
	GridItem* getItemForPos(float, float, bool);
	int getAdditionalScrollBarWidth(MinecraftClient*);
	bool shouldUseMouseScrollbarLayout(MinecraftClient*);
	void scrollDownBy(float);
	void scrollUpBy(float);
	void beginTracking(float, float, int);
	void setContentOffset(Vec3);
	void snapContentOffsetToBounds(bool);
	void updateScrollFade(ScrollBar&);
	void onHoldItem();
	void touchesCancelled(float, float, int);
	void touchesEnded(float, float, int);
	void _onSelect(int);
	void queryHoldTime(int*, int*);
	void translate(float, float);
	void addFlag(int);
	int getScrollT() const;
	void setSelected(int, bool);
	void onNavigate(int);
	void tick();
	void adjustContentSize();
	void hideScrollIndicators();
	void stopDecelerationAnimation();
	void startDecelerationAnimation(bool);
	int contentOffset();
	void updateVerticalScrollIndicator();
	void updateHorizontalScrollIndicator();
	void touchesMoved(float, float, int);
	void setContentOffset(float, float);
	void setContentOffsetWithAnimation(Vec3, bool);
	void stepThroughDecelerationAnimation(bool);
};
