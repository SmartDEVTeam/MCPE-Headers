#pragma once

#include "Screen.h"
//class TButton;

class DeathScreen : public Screen {
public:

/*this doesn't work!*/
//std::shared_ptr<Touch::TButton> respawnButton;
//std::shared_ptr<Touch::TButton> quitButton;

	DeathScreen(MinecraftClient&)

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
