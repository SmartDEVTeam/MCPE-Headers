#pragma once

#include "Screen.h"
#include "AbstractScreen.h"
class Vec3;
class LevelRenderer;
class Player;
class FrustumData;

class InGamePlayScreen : public Screen, public AbstractScreen
{
public:
	InGamePlayScreen(MinecraftClient&);

	virtual ~InGamePlayScreen();
	virtual void _init(int, int);
	virtual void onFocusGained();
	virtual void tick(int, int);
	virtual void applyInput(float);
	virtual void render(ScreenContext&);
	virtual void handleDirection(DirectionId, float, float);
	virtual bool renderGameBehind() const;
	virtual bool isModal() const;
	virtual bool isShowingMenu() const;
	virtual bool shouldStealMouse() const;
	virtual bool renderOnlyWhenTopMost() const;
	virtual std::string getScreenName();
	virtual void getSendTelemetry();
	virtual void _renderLevelPrep(float);
	virtual void _renderLevel(float);
	virtual void _preLevelRender(ScreenContext&);
	virtual void _postLevelRender(ScreenContext&);
	virtual void _renderedFramedItems(Vec3, LevelRenderer&, float);
	virtual void _updateFreeformPickDirection(float, Vec3&, Vec3&);
	virtual void _saveMatrices();
	virtual void _renderFirstPerson3DObjects(LevelRenderer&, float);
	virtual void _renderTransparentFirstPerson3DObjects(LevelRenderer&, float);
	virtual void _renderItemInHand(Player&, float);
	virtual bool _shouldClipPiquids() const;
	virtual void _getThirdPersonSetting();
	virtual bool _isHoloViewer() const;
	virtual void _prepareCuller(FrustumData&, FrustumData&);
	virtual void _localPlayerTurned(float);
	virtual void _getPickRange();
	virtual void _shouldPushHUD();
};
