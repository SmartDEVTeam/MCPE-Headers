#pragma once

#include <string>

class App {
public:
    virtual ~App();
	virtual void quit();
	virtual void init();
};
