#pragma once

class AppPlatformListener {
public:
	char apl_vars[4];

	AppPlatformListener(bool);
	AppPlatformListener();
	virtual ~AppPlatformListener();
	virtual void onLowMemory();
	virtual void onAppSuspended();
	virtual void onAppResumed();
	virtual void onAppFocusLost();
	virtual void onAppFocusGained();
	virtual void onAppTerminated();
	void initListener(float);
	void terminate();
};
