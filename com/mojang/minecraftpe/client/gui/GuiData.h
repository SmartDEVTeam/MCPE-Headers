#pragma once

#include "../AppPlatformListener.h"

class MinecraftClient;
class Config;

class GuiData : public AppPlatformListener {
public:
	GuiData(MinecraftClient&);
	virtual ~GuiData();
	virtual void onConfigChanged(const Config&);
	virtual void onAppSuspended();
	void showPopupNotice(const std::string&, const std::string&);
};
