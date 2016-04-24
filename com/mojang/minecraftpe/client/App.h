#pragma once

#include <string>
#include "AppPlatformListener.h"

class AppContext;
class Token;

// Size : 28
class App : public AppPlatformListener {
public:
	bool hasInitiated; // 8
	bool wantsToQuit; // 9
	AppContext& appContext; // 12
	char app_vars[12]; // 16

public:
	App(int, char**);
	virtual ~App();
	virtual void audioEngineOn();
	virtual void audioEngineOff();
	virtual void muteAudio();
	virtual void unMuteAudio();
	virtual void destroy();
	virtual void loadState(void*, int);
	virtual bool saveState(void**, int*);
	virtual bool useTouchscreen();
	virtual void setTextboxText(const std::string&);
	virtual void draw();
	virtual void update();
	virtual void setSize(int, int, float);
	virtual void quit();
	virtual void wantToQuit();
	virtual void init();
	void init(AppContext&);
	void changeContext(AppContext&);
	Token* getCommandLineParameter(const std::string&);
};
