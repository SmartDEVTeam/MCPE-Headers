#pragma once

#include "Screen.h"

#include "../../../world/level/BlockPos.h"
#include "../../../world/item/ItemInstance.h"
#include "../InventoryPane.h"
#include "../CraftingType.h"


class Tessellator;
class ItemPack;
class Recipe;
class ArmorSlot;
class ImageButton;
class CategoryButton;
class NinePatchLayer;
class Label;
class BlankButton;
class ImageWithBackground;

class InventoryScreen : public Screen, public Touch::IInventoryPaneCallback {
public:
	struct TabButtonWithMeta;
	struct IngredientSlotStatus;
	
	enum class InventoryPaneType : unsigned int {
		INVENTORY,
		CRAFTING,
		ARMOR,
		BLOCKS,
		DECORATIONS,
		TOOLS,
		ITEMS
	};
	
	char is_vars[60]; // 136
	void* somethingOfImportance; // 196 
	char is_vars0[60]; // 200
	std::shared_ptr<ImageWithBackground> closeButton; // 260;
	std::shared_ptr<NinePatchLayer> layer_0; // 268
	std::shared_ptr<NinePatchLayer> layer_1; // 276
	std::shared_ptr<NinePatchLayer> layer_2; // 284
	std::shared_ptr<NinePatchLayer> layer_3; // 292
	std::shared_ptr<NinePatchLayer> layer_4; // 300
	std::shared_ptr<NinePatchLayer> layer_5; // 308
	std::shared_ptr<NinePatchLayer> layer_6; // 316
	std::shared_ptr<NinePatchLayer> layer_7; // 324
	std::shared_ptr<Touch::InventoryPane> inventory; // 332
	std::shared_ptr<Touch::InventoryPane> armor; // 340
	std::shared_ptr<Touch::InventoryPane> crafting; // 348
	std::shared_ptr<Touch::InventoryPane> creativePanes[4]; // 356
	std::shared_ptr<BlankButton> blankButton; // 388
	std::shared_ptr<BlankButton> blankButton2; // 396
	std::shared_ptr<BlankButton> blankButton3; // 404
	std::shared_ptr<BlankButton> blankButton4; // 412
	std::shared_ptr<Touch::TButton> someButton; // 420
	char is_vars1[512 - 428]; // 428
	std::vector<InventoryScreen::TabButtonWithMeta*> buttonTabs; // 512
	char is_vars2[100]; // 516
	InventoryScreen::InventoryPaneType selectedPaneType; // 616
	char is_vars3[656 - 620]; // 620
	ItemInstance item; // 656
	bool hasDumpedArmor; // 676
	char is_vars4[716 - 680]; // 680
	std::shared_ptr<Label> recipesName; // 728
	std::shared_ptr<Label> noRecipesName; // 736
	CraftingType craftingType; // 744
	char is_vars5[864 - 748]; // 748
	std::string cannotCreateString; // 864
	bool idk_b; // 868
	char is_vars6[8]; // 872
	BlockPos blockPos; // 880
	

	InventoryScreen(MinecraftClient&, CraftingType, const BlockPos&);
	virtual ~InventoryScreen();
	virtual void onInternetUpdate();
	virtual void handleButtonPress(short);
	virtual void handleButtonRelease(short);
	virtual void handleBackEvent(bool);
	virtual bool renderGameBehind() const;
	virtual bool closeOnPlayerHurt() const;
	virtual bool isModal() const;
	virtual std::string getScreenName();
	virtual void render(int, int, float);
	virtual void init();
	virtual void setupPositions();
	virtual void tick();
	virtual void handleScrollWheel(float);
	virtual void _updateTabButtonSelection();
	virtual void _buttonClicked(Button&);
	virtual void _pointerReleased(int, int);
	virtual void _controllerDirectionChanged(int, StickDirection);
	virtual void _controllerDirectionHeld(int, StickDirection);
	virtual bool addItem(Touch::InventoryPane&, int);
	virtual bool isAllowed(int);
	virtual std::vector<const ItemInstance*> getItems(const Touch::InventoryPane&);
	
	void _addItemArmorScreen(int);
	bool _addItemCraftingScreen(int);
	int _addItemCreativeScreen(ItemInstance&, bool, bool);
	int _addItemCreativeScreen(int, int, bool, bool);
	bool _addItemForInventoryPane(int&);
	void _closeWindow();
	void _drawSlotItemAt(Tessellator&, int, const ItemInstance*, int, int, bool);
	bool _entityCheck();
	int _getNumberOfIngredients(ItemInstance&, ItemPack&);
	ItemPack& _getPlayerInventoryItemPack();
	void _handleAddItem(Touch::InventoryPane&, int, bool);
	void _handleArmorInventoryNavigation(StickDirection);
	void _handleArmorJoyStickNavigation(StickDirection);
	void _handleArmorSlotNavigation(StickDirection);
	void _onBulkSelectCreativePane();
	void _populateFilteredItems();
	void _populateItem(const ItemInstance&);
	void _populateItems();
	void _putItemInToolbar(const ItemInstance*);
	void _refreshCraftingGrid(Recipe*);
	void _refreshCraftingItemList(const std::vector<Recipe*>&);
	void _renderArmorScreen(Tessellator&, int, int, float);
	void _renderCraftingScreen(Tessellator&, int, int, float);
	void _renderGridItem(ItemInstance*, InventoryScreen::IngredientSlotStatus, int, int);
	void _renderPlayer(float, float, float);
	void _selectInDirection(StickDirection);
	void _setCurrentRecipe(Recipe*);
	void _takeAndClearArmorSlot(ArmorSlot);
	void _updateArmorItems();
	void _updateCraftableItems(bool);
	void _updateCraftingButtonVisiblity();
	void _updateIngredientCountFromRecipe(Recipe*, bool, ItemPack&);
	void clearPopulatedItems();
	std::shared_ptr<CategoryButton> createInventoryTabButton(int, bool);
	void drawIcon(InventoryScreen::InventoryPaneType, std::shared_ptr<ImageButton>, bool, bool);
	ItemInstance getItemFromType(InventoryScreen::InventoryPaneType);
};