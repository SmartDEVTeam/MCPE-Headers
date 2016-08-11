#pragma once

#include "Screen.h"
#include "AbstractScreen.h"
class LevelSummary;

enum class CreateWorldScreenType {
	CREATE_WORLD
};

class CreateWorldScreen : public Screen, AbstractScreen
{
public:
	CreateWorldScreen(MinecraftClient*, CreateWorldScreenType);
	CreateWorldScreen(MinecraftClient*, const LevelSummary&);

	virtual ~CreateWorldScreen();
	virtual void onSetKeyboardHeight(float);
	virtual void handleButtonRelease(short);
	virtual void handleBackEvent(bool);
	virtual void handleTextChar(const std::string&, bool);
	virtual void handleCaretLocation(int);
	virtual void setTextboxText(const std::string&);
	virtual std::string getScreenName();
	virtual void render(int, int, float);
	virtual void init();
	virtual void setupPositions();
	virtual void tick();
	virtual void _buttonClicked(Button&);
	virtual void _guiElementClicked(GuiElement&);
	virtual void _pointerPressed(int, int);
	virtual void _pointerReleased(int, int);
	virtual void _controllerDirectionChanged(int, StickDirection);
};
