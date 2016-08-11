#pragma once

#include "../MaterialPtr.h"

class Entity;
class Color;

class EntityShaderManager {
public:
	mce::MaterialPtr entity; // 4
	mce::MaterialPtr entity_alphatest; // 16
	mce::MaterialPtr entity_static; // 28

	EntityShaderManager();
	virtual ~EntityShaderManager();
	virtual void _getOverlayColor(Entity&, float) const;
	void _setupShaderParameters(Entity&, const Color&, const Color&, float, bool);
	void _setupShaderParameters(Entity&, const Color&, float, bool);
	void _setupShaderParameters(Entity&, float);
	void _setupShaderParameters(float, const Color&, bool);
};
