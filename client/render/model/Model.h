#pragma once

#include "../../AppPlatformListener.h"

class Entity;

class Model
{
public:
	Model();

	virtual ~Model();
	virtual void onAppSuspended();
	virtual void clear();
	virtual void render();
	virtual void render(Entity&, float, float, float, float, float, float);
	virtual void setupAnim(float, float, float, float, float, float);
	virtual void prepareMobModel(Mob&, float, float, float);
	virtual void* getLeashOffsetPosition() const;
	virtual void* getHeightAdjustment() const;
};
