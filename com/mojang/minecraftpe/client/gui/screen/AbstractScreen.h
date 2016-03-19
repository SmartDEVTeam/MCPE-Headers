#pragma once

#include <string>

class BlockPos;
class UIRenderContext;
class InputMode;
class DirectionId;
class VoiceCommand;
namespace UI { class GameEventNotification; };

class AbstractScreen {
public:
	virtual ~AbstractScreen();
	virtual void _init(int, int) = 0;
	virtual void setSize(int, int) = 0;
	virtual void onSetKeyboardHeight(float) = 0;
	virtual void setAssociatedBlockPos(const BlockPos&) = 0;
	virtual void onInternetUpdate() = 0;
	virtual void onFocusGained() = 0;
	virtual void onFocusLost() = 0;
	virtual void terminate() = 0;
	virtual void onGameEventNotification(UI::GameEventNotification);
	virtual void tick(int, int) = 0;
	virtual void updateEvents() = 0;
	virtual void applyInput(float);
	virtual void setupAndRender(UIRenderContext&, unsigned short, int, int, float) = 0;
	virtual void handleInputModeChanged(InputMode) = 0;
	virtual void handleButtonPress(short) = 0;
	virtual void handleButtonRelease(short) = 0;
	virtual void handlePointerLocation(short, short) = 0;
	virtual void handlePointerPressed(bool) = 0;
	virtual void handleDirection(DirectionId, float, float) = 0;
	virtual void handleBackEvent(bool) = 0;
	virtual void handleTextChar(const std::string&, bool) = 0;
	virtual void handleCaretLocation(int) = 0;
	virtual void setTextboxText(const std::string&) = 0;
	virtual void handleLicenseChanged() = 0;
	virtual void handleGazeGestureInput(short, float, float, float) = 0;
	virtual void handleDictationEvent() = 0;
	virtual void handleCommandEvent(const VoiceCommand&) = 0;
	virtual bool renderGameBehind() const = 0;
	virtual bool closeOnPlayerHurt() const = 0;
	virtual bool isModal() const;
	virtual bool isShowingMenu() const;
	virtual bool shouldStealMouse() const;
	virtual void getFocusedControl();
	virtual bool isWorldViewer() const;
	virtual bool isPauseScreen() const;
	virtual bool renderOnlyWhenTopMost() const;
	virtual int getWidth() = 0;
	virtual int getHeight() = 0;
	virtual int getNumberOfRenderPasses() const;
};
