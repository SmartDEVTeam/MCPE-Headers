#pragma once

#include "Screen.h"

class Button;
class TButton;

class DeathScreen : public Screen {
public:

std::shared_ptr<Touch::TButton> respawnButton;
std::shared_ptr<Touch::TButton> quitButton;

   virtual void render(int, int, float);
	virtual void init();
	virtual void setupPositions();
	virtual void tick();
   virtual void _buttonClicked(Button&);
};