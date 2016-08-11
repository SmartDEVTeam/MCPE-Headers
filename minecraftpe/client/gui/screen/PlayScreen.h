#pragma once

#include "Screen.h"
#include "AbstractScreen.h"

class PlayScreen : public Screen, public AbstractScreen
{
public:
	PlayScreen(MinecraftClient&, bool);

	virtual ~PlayScreen();
	virtual void onFocusGained();
	virtual void handleButtonPress(short);
	virtual void handleBackEvent(bool);
	virtual std::string getScreenName();
	virtual void render(int, int, float);
	virtual void init();
	virtual void setupPositions();
	virtual void tick();
	virtual void _buttonClicked(Button&);
	virtual void _controllerDirectionChanged(int, StickDirection);
};
