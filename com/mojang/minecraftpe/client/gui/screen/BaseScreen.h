#pragma once

#include <memory>

#include "AbstractScreen.h"

class AbstractScreenSetupCleanupStrategy;

class BaseScreen : public AbstractScreen {
public:
	//void** vtable; // 0
	std::unique_ptr<AbstractScreenSetupCleanupStrategy> cleanupStrategy; // 4
	
	BaseScreen();
	virtual ~BaseScreen();
	virtual std::string getScreenName();
	virtual void toGUICoordinate(int, int, int&, int&);
	void cleanupForRendering(ScreenContext&);
	void getEyeRenderingMode();
	void setScreenSetupCleanup(std::unique_ptr<AbstractScreenSetupCleanupStrategy>);
	void setupForRendering(ScreenContext&);
};
