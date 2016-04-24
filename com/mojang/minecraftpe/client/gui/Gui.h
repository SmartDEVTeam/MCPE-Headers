#pragma once

#include "GuiComponent.h"
#include "../AppPlatformListener.h"

class MinecraftClient;
class Config;

class Gui : public GuiComponent, public AppPlatformListener {
public:
	Gui(MinecraftClient&);
	virtual ~Gui();
	virtual void onAppSuspended();
	virtual void onConfigChanged(const Config&);
	void renderToolBar(float, float, bool);
	void renderProgressIndicator(int, int, float);
	void showPopupNotice(const std::string&, const std::string&);
	void renderOnSelectItemNameText(int, Font*, int);
};
