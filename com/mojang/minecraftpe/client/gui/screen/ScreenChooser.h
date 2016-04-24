#pragma once

#include <string>
#include <memory>
#include <functional>
#include "BaseScreen.h"
#include "../CraftingType.h"

class Player;
class ChestTileEntity;
class BlockPos;
class SignTileEntity;
class LevelSummary;
class EnchantingTableEntity;
class BrewingStandTileEntity;
class FurnaceTileEntity;
class SkinPack;
class UIScreenType;
typedef int StorageVersion;

class ScreenChooser {
public:
	MinecraftClient& client;
	
	ScreenChooser(MinecraftClient&, UIScreenType, bool);
	~ScreenChooser();
	void _pushScreen(std::shared_ptr<BaseScreen>, bool);
	void* pushPausePrevScreen();
	void* pushPauseScreen();
	void* pushGamePadLayoutScreen(bool);
	void* enableNewScreens(bool);
	void* isNewScreensEnabled() const;
	void* pushAddExternalServerScreen();
	void* pushConsoleScreen();
	void* pushChestScreen(Player*, ChestTileEntity*);
	void* pushAnvilScreen(Player*, BlockPos const&);
	void* pushChatScreen();
	void* popScreen(AbstractScreen&, int);
	void* pushInBedScreen();
	void* pushLanguageScreen();
	void* pushKeyboardLayoutScreen(bool);
	void* setDisconnectScreen(std::string const&);
	void* pushRemotePlayScreen();
	void* setStartMenuScreen();
	void* pushMakeInfiniteScreen(LevelSummary const&, StorageVersion);
	void* pushCreateWorldScreen(LevelSummary const&);
	void* setXblLoginScreen();
	void* pushDeathScreen();
	void* pushEnchantingScreen(Player*, EnchantingTableEntity*);
	void* pushBrewingStandScreen(Player*, BrewingStandTileEntity*);
	void* pushFurnaceScreen(Player*, FurnaceTileEntity*);
	void* getInBedScreen();
	void* pushMobEffectsScreen();
	void* setUpsellScreen(bool);
	void* pushProgressScreen(bool, std::function<void ()>);
	void* pushSelectSkinTypeScreen(bool, bool, std::string const&);
	void* pushShowSkinPackScreen(SkinPack const&, std::string const&, bool);
	void* pushTextEditScreen(SignTileEntity*);
	void* setGameplayScreen();
	void* pushMessageBoxScreen(std::string const&);
	void* pushSkinsScreen();
	void* pushOptionsScreen(bool, bool, std::string const&);
	void* pushLocalPlayScreen(bool, bool);
	void* pushDeleteWorldScreen(LevelSummary const&);
	void* pushInventoryScreen(CraftingType);
};
