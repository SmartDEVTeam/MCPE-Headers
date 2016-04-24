#pragma once

// 0.14.0

#include <functional>
#include <memory>
#include "App.h"
#include "../gamemode/GameType.h"
#include "../world/phys/Vec3.h"

class AbstractScreen;
class Font;
class GameRenderer;
class Gui;
class Screen;
class ScreenChooser;
class Minecraft;
class Music;
class BuildActionIntention;
class Level;
class Mob;
class Dimension;
class Timer;
class Options;
class VoiceCommand;
class DirectionId;
class InputMode;
class Side;
class HolographicPlatform;
class VoiceSystem;
class Player;
class LocalPlayer;
class LevelSettings;
class SoundEngine;
class TextureAtlas;
class TextureGroup;
class GameStore;
class GeometryGroup;
class SkinRepository;
class MinecraftTelemetry;
class ExternalServerFile;
class UIDefRepository;
class MobEffectsLayout;
class LevelRenderer;
class HolosceneRenderer;
class ParticleEngine;
class MinecraftInputHandler;
class MusicManager;
class LevelArchiver;
class SnoopClient;
class Entity;
namespace UI { class GameEventNotification; };
namespace Social { 
	class UserManager; 
	class Multiplayer;
	namespace Telemetry {
		class TelemetryManager;
	};
};

// Size : 472
class MinecraftClient : public App {
public:
	static int INTERACTION_FREQ_MS;
	static int _hasInitedStatics;
	static float GUI_SCALE_VALUES[8];

public:
	char mcclient_vars[36]; // 28
	std::string worldPath; // 64
	std::string mainPath; // 68
	std::string idk_s; // 72
	int width; // 76
	int height; // 80
	char mcclient_vars1[4]; // 84
	Minecraft* minecraft; // 88
	std::unique_ptr<LevelRenderer> levelRenderer; // 92
	GameRenderer* gameRenderer; // 96
	HolosceneRenderer* holoRenderer; // 100
	ParticleEngine* particleEngine; // 104
	ExternalServerFile* serverFile; // 108
	TextureGroup* textureGroup; // 112 
	Font* defualtFont; // 116
	Font* runeFont; // 120
	Entity* targetEntity; // 124
	char mcclient_vars2[12]; // 128
	bool isMouseGrabbed; // 140
	char* connectedServer; // 144
	char mcclient_vars3[12]; // 148
	bool inhibitDueToTextBoxMode; // 160
	int filler_i; // 164
	char mcclient_vars4[40]; // 168
	bool isDictionaryDataAvailable; // 208
	char* dictationText; // 212
	char mcclient_vars5[48]; // 216
	std::unique_ptr<LocalPlayer> localPlayer; // 264
	MinecraftInputHandler* mcInputHandler; // 268
	std::unique_ptr<HolographicPlatform> holoInput; // 272
	void* voidSystem; // 276
	Gui* gui; // 280
	UIDefRepository* UIRepo; // 284
	Options* options; // 288
	SoundEngine* soundEngine; // 292
	MusicManager* musicManager; // 296
	SnoopClient* snoopClient; // 300
	char mcclient_vars6[4]; // 304
	MobEffectsLayout* mobEffectsLayout; // 308
	GameStore* gameStore; // 312
	GeometryGroup* geometryGroup; // 316
	SkinRepository* skinRepo; // 320
	Social::UserManager* userManager; // 324
	Social::Multiplayer* multiplayer; // 328
	LevelArchiver* levelArchiver; // 332
	TextureAtlas* blockAtlas; // 336
	TextureAtlas* itemAtlas; // 340
	char mcclient_vars7[8]; // 344
	ScreenChooser* screenChooser; // 352
	char mcclient_vars8[16]; // 356
	bool idk_b; // 372
	int filler_i2; // 376
	char mcclient_vars9[16]; // 380
	float dPadScale; // 396
	char mcclient_vars10[32]; // 400
	bool isEdu; // 432
	bool isMcWorld; // 433
	std::string idk_s1; // 436  (set to Util::EMPTY_STRING)
	char mcclient_vars11[4]; // 440
	float keyboardHeight; // 444
	char mcclient_vars12[12]; // 448
	Social::Telemetry::TelemetryManager* telemetryManager; // 460

public:
	MinecraftClient(int, char **);
	virtual ~MinecraftClient();
	virtual void onLowMemory();
	virtual void onAppSuspended();
	virtual void onAppResumed();
	virtual void onAppFocusLost();
	virtual void onAppFocusGained();
	virtual void audioEngineOn();
	virtual void audioEngineOff();
	virtual void muteAudio();
	virtual void unMuteAudio();
	virtual bool useTouchscreen();
	virtual void setTextboxText(std::string const &);
	virtual void update();
	virtual void setSize(int, int, float);
	virtual void init();
	virtual void handleBack(bool);
	virtual void handleBack();
	virtual void onInternetUpdate();
	virtual void onLevelCorrupt();
	virtual void onGameModeChanged();
	virtual void createSkin();
	virtual void onTick(int, int);
	virtual void vibrate(int);
	void _getGuiScaleForLargeScreen(int, int);
	void _getGuiScaleForSmallScreen(int, float);
	void _initMinecraftClient();
	void _popScreen();
	void _processNewGazeHoloScreenData();
	void _reloadFancy(bool);
	void _reloadLanguages();
	bool allowPicking();
	void cancelLocateMultiplayer();
	void checkForPiracy();
	void clearDictationDataAvailable();
	void endFrame();
	void forEachScreen(std::function<bool (std::shared_ptr<AbstractScreen> &)>);
	void forEachVisibleScreen(std::function<void (std::shared_ptr<AbstractScreen> &)>);
	void getCameraTargetEntity() const;
	void getClientRandomId() const;
	void getClientUUID() const;
	void getConnectedPort() const;
	char* getConnectedServer() const;
	char* getDictationText() const;
	float getDpadScale();
	ExternalServerFile* getExternalServer() const;
	Font* getFont() const;
	GameRenderer* getGameRenderer() const;
	GameStore* getGameStore() const;
	Gui* getGui() const;
	int getHeight() const;
	void getHoloInput() const;
	void getHolosceneRenderer() const;
	void getHoloscreenHalfWidth() const;
	void getHoloviewerScale();
	void getInput() const;
	void getKeyboardHeight() const;
	void getLevelRenderer() const;
	LocalPlayer* getLocalPlayer();
	bool getMouseGrabbed() const;
	void getMultiplayer() const;
	Options* getOptions();
	void getParticleEngine() const;
	void getRuneFont() const;
	Screen* getScreen();
	Screen* getScreen() const;
	ScreenChooser* getScreenChooser() const;
	Minecraft* getServer();
	Music* getSituationalMusic();
	void getSkinRepository();
	void getSoundEngine() const;
	void getTelemetry() const;
	TextureGroup* getTextures() const;
	void getUIDefRep() const;
	void getVoiceSystem() const;
	void getUserManager() const;
	int getWidth() const;
	void grabMouse();
	void handleAttackActionButtonRelease();
	void handleBackNoReturn();
	void handleBiomeDisplayButtonPress();
	void handleBuildActionButtonRelease();
	void handleBuildAction(BuildActionIntention &);
	void handleBuildOrAttackButtonPress();
	void handleCaretLocation(int);
	void handleBuildOrInteractButtonPress();
	void handleChatButtonRelease();
	void handleConsoleButtonRelease();
	void handleCommandEvent(const VoiceCommand&);
	void handleCraftingButtonPress();
	void handleCreativeBlockSelectButtonRelease();
	void handleDebugToggleAnchorsCommand();
	void handleDebugToggleLSRCommand();
	void handleDecreaseRenderDistanceButtonPress();
	void handleDecrementMaxCullingStepsButtonPress();
	void handleDestoryOrAttackButtonPress();
	void handleDestroyOrInteractButtonPress();
	void handleDictationEvent();
	void handleDismountButtonPress();
	void handleDropAllButtonPress();
	void handleDropAllItemsButtonPress();
	void handleDropButtonPress();
	void handleHideGuiButtonPress();
	void handleIncreaseRenderDistanceButtonPress();
	void handleIncrementMaxCullingStepsButtonPress();
	void handleInputModeChanged(InputMode);
	void handleInventoryButtonPress();
	void handleInventoryMoveButtonPress(int);
	void handleInvite();
	void handleLicenseChanged();
	void handleLowMemoryWarningButtonPress();
	void handleMemoryStatsButtonPress();
	void handleMenuButtonPress(short);
	void handleMenuButtonRelease(short);
	void handleMobEffectsButtonPress();
	void handleNextAVCStatButtonPress();
	void handleNextAVCStatButtonRelease();
	void handlePaddleButtonPress(Side);
	void handlePaddleButtonRelease(Side);
	void handlePauseButtonPress();
	void handlePickDebugObjectButtonPress();
	void handlePointerLocation(short, short);
	void handlePointerPressedButtonPress();
	void handlePointerPressedButtonRelease();
	void handleRedstoneLogButtonPress();
	void handleReloadUIDefinitions();
	void handleRenderDebugButtonPress();
	void handleSetSpawnPositionButtonPress();
	void handleShowUpsellScreen(bool);
	void handleSlotSelectButtonPress(int);
	void handleSuspendResumeButtonPress();
	void handleTextChar(const std::string&, bool);
	void handleTimeStepForwardButtonPress();
	void handleToggleAdvancedCullingButtonPress();
	void handleToggleDayCycleActiveButtonPress();
	void handleToggleEnableNewScreensDebugButtonPress();
	void handleToggleFlyFlastButtonPress();
	void handleToggleFrameTimerDisplayButtonPress();
	void handleToggleGameModeButtonPress();
	void handleToggleNoClipButtonPress();
	void handleTogglePlayerUpdateMobsButtonPress();
	void handleToggleShowChunkMapButtonPress();
	void handleToggleSimulateTouchButtonPress();
	void handleToggleThirdPersonViewButtonPress();
	void handleVectorInput(short, float, float, float);
	void initFoliageAndBlockTextureTessellator();
	void initOptionObservers();
	void initSnoopClient();
	void initializeTrialWorld(Player*);
	bool isEduMode() const;
	bool isInGame();
	bool isKindleFire(int);
	bool isRealityFullVRMode();
	bool isSRPlacementMode() const;
	bool isScreenReplaceable() const;
	bool isServerVisible();
	bool isShowingMenu() const;
	void joinLiveGame(const std::string&);
	void joinMultiplayer(const char*, int);
	void leaveGame(bool);
	void locateMultiplayer();
	void newDictationDataAvailable() const;
	void onClientStartedLevel(std::unique_ptr<Level>, std::unique_ptr<LocalPlayer>);
	void onDimensionChanged();
	void onGameEventNotification(UI::GameEventNotification);
	void onMobEffectsChange();
	void onPlayerLoaded(Player&);
	void onPrepChangeDimension();
	void onStereoEnabledChanged();
	void onUserSignin();
	void onUserSignout();
	void play(const std::string&, const Vec3&, float, float);
	void playUI(const std::string&, float, float);
	void pushScreen(std::shared_ptr<AbstractScreen>, bool);
	void popScreen(int);
	void refocusMouse();
	void releaseMouse();
	void reloadShaders();
	void resetInhibitInputDueToTextBoxMode();
	void restartServer();
	void resetInput();
	void sendHardwareSnoopEvent();
	void setCameraTargetEntity(Entity*);
	void sendLocalMessage(const std::string&, const std::string&);
	void setDpadScale(float);
	void setGameMode(GameType);
	void setHoloInput(std::unique_ptr<HolographicPlatform>);
	void setHoloscreenHalfWidth(float);
	void setHoloviewerPlayerMode(bool, bool);
	void setInhibitInputDueToTextBoxMode();
	void setKeyboardHeight(float);
	void setInviteHandle(const std::string&);
	void setSuspendInput(bool);
	void setVoiceSystem(std::unique_ptr<VoiceSystem>);
	void setupCommandParser();
	void setupLevelRendering(Level*, Dimension*, Entity*);
	void setupRenderer();
	void startFrame();
	void startHoloviewerReveal();
	void startLocalServer(std::string, std::string, LevelSettings);
	void teardownRenderer();
	void tickBuildAction();
	void tickInput();
	void toggleThirdPersonView();
	void transformResolution(int*, int*);
	void updateGraphics(const Timer&);
	void updateScheduledScreen();
	void updateStats();
	bool useController();
};
