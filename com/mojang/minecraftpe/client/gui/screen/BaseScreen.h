#pragma once

#include <memory>

#include "AbstractScreen.h"

class AbstractScreenSetupCleanupStrategy;

class BaseScreen : public AbstractScreen {
public:
	//void** vtable; // 0
	AbstractScreenSetupCleanupStrategy* cleanupStrategy; // 4
	
	BaseScreen();
	virtual ~BaseScreen();
	virtual void toGUICoordinate(int, int, int&, int&);
	void cleanupForRendering(unsigned short);
	void setScreenSetupCleanup(std::unique_ptr<AbstractScreenSetupCleanupStrategy>);
	void setupForRendering(unsigned short, float);
};
