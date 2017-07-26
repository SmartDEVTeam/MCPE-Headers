#pragma once

class Entity;

class EntityShaderManager
{
public:
	EntityShaderManager();

	virtual ~EntityShaderManager();
	virtual void* _getOverlayColor(Entity&, float) const;
};
