#pragma once

#include "EntityShaderManager.h"

class Options;
struct Vec2;
struct Vec3;
class EntityRenderDispatcher;
namespace mce { class TextureGroup; };

class EntityRenderer : public EntityShaderManager
{
public:
	void**vtable; // just to be sure

	EntityRenderer(EntityRenderDispatcher&, mce::TextureGroup&, bool);
	
	virtual ~EntityRenderer();
	virtual int _getOffset();
	virtual void* _getFont();
	virtual bool _isRealityFullVRMode();
	//virtual void __cxa_pure_virtual;
	virtual void renderDebug(Entity&, Options&);
	virtual void renderEffects(Entity&, const Vec3&, float, float);
	virtual void renderTrading(Entity&, float, const Vec3&, float);
	virtual void renderLeash(Entity&, const Vec3&, float, float);
	virtual void renderWaterHole(Entity&, const Vec3&, const Vec2&, float);

	bool isFancy();
	bool hasWaterHole() const;
	void* getTextureAtlas();
};
