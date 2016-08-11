#pragma once

#include "Screen.h"

class DeathScreen : public Screen {
public:
	DeathScreen(MinecraftClient&);

	virtual void handleButtonPress(short);
	virtual bool renderGameBehind() const;
	virtual std::string getScreenName();
	virtual void render(int, int, float);
	virtual void init();
	virtual void setupPositions();
	virtual void tick();
	virtual void buttonClicked(Button&);
	virtual void _controllerDirectionChanged(int, StickDirection);
};
