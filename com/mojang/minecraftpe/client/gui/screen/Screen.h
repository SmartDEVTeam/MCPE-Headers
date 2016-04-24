#pragma once

#include <memory>
#include <vector>
#include "../GuiComponent.h"
#include "BaseScreen.h"

namespace Touch { class TButton; };


class StickDirection;
class MinecraftClient;
class Button;
class TextBox;
class GuiElement;
class MCOEvent;
class MojangConnectionStatus;
class ControllerButtonRenderer;

// Size : 160
class Screen : public BaseScreen, public GuiComponent {
public:
	//void* vtable; // 8
	int width; // 12
	int height; // 16
	MinecraftClient* mcClient; // 20
	std::vector<std::shared_ptr<Button>> buttonList; // 24
	std::vector<std::shared_ptr<TextBox>> textboxList; // 36
	std::vector<std::shared_ptr<Button>> tabButtonList; // 48
	std::vector<std::shared_ptr<GuiElement>> tabElementList; // 60
	std::vector<std::shared_ptr<GuiElement>> guiElementList; // 72
	int tabButtonIndex; // 84
	int tabElementIndex; // 88
	std::unique_ptr<ControllerButtonRenderer> buttonRenderer; // 92
	Font* font; // 96
	Button* buttonClicked; // 100
	char screen_vars6[32]; // 104

	Screen(MinecraftClient&);
	virtual ~Screen();
	virtual void _init(int, int);
	virtual void setSize(int, int);
	virtual void onSetKeyboardHeight(float);
	virtual void setAssociatedBlockPos(const BlockPos&);
	virtual void onInternetUpdate();
	virtual void onFocusGained();
	virtual void onFocusLost();
	virtual void terminate();
	virtual void tick(int, int);
	virtual void updateEvents();
	virtual void setupAndRender(UIRenderContext&, unsigned short, int, int, float);
	virtual void handleInputModeChanged(InputMode);
	virtual void handleButtonPress(short);
	virtual void handleButtonRelease(short);
	virtual void handlePointerLocation(short, short);
	virtual void handlePointerPressed(bool);
	virtual void handleDirection(DirectionId, float, float);
	virtual void handleBackEvent(bool);
	virtual void handleTextChar(const std::string&, bool);
	virtual void handleCaretLocation(int);
	virtual void setTextboxText(const std::string&);
	virtual void handleLicenseChanged();
	virtual void handleGazeGestureInput(short, float, float, float);
	virtual void handleDictationEvent();
	virtual void handleCommandEvent(const VoiceCommand&);
	virtual bool renderGameBehind() const;
	virtual bool closeOnPlayerHurt() const;
	virtual int getWidth();
	virtual int getHeight();
	virtual void toGUICoordinate(int, int, int&, int&);
	virtual void render(int, int, float);
	virtual void init();
	virtual void setupPositions();
	virtual void checkForPointerEvent();
	virtual void controllerEvent();
	virtual void tick();
	virtual void renderBackground(int);
	virtual void renderDirtBackground();
	virtual void renderMenuBackground(float);
	virtual void confirmResult(bool, int);
	virtual void supppressedBySubWindow();
	virtual void onTextBoxUpdated(int);
	virtual void onMojangConnectorStatus(MojangConnectionStatus);
	virtual void handleScrollWheel(float);
	virtual void _handlePointerAction(int, int, bool);
	virtual void _updateTabButtonSelection();
	virtual void _buttonClicked(Button&);
	virtual void _guiElementClicked(GuiElement&);
	virtual void _pointerPressed(int, int);
	virtual void _pointerReleased(int, int);
	virtual void _controllerDirectionChanged(int, StickDirection);
	virtual void _controllerDirectionHeld(int, StickDirection);
	int _getCursorMoveThrottle();
	void _processControllerDirection(int);
	void _tabNext();
	void _tabPrev();
	void renderProgressBar(float);
	void setButtonIndex(int);
};
