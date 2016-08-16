#pragma once

class PushNotificationMessage;

// size: 4
// 0.15.6
class AppPlatformListener {
public:
	char apl_vars[4]; // 4

	AppPlatformListener();
	AppPlatformListener(bool);

	virtual ~AppPlatformListener();
	virtual void onLowMemory();
	virtual void onAppSuspended();
	virtual void onAppResumed();
	virtual void onAppFocusLost();
	virtual void onAppFocusGained();
	virtual void onAppTerminated();
	virtual void onPushNotificationRecieved(const PushNotificationMessage&);
	void initListener(float);
	void terminate();
};
