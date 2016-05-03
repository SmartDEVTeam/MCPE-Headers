#pragma once

#include <string>
#include "EntityShaderManager.h"
#include "../TexturePtr.h"

class EntityRenderDispatcher;
class Vec3;
class Vec2;
class Font;
class Options;
namespace mce { class TextureGroup; };

class EntityRenderer : public EntityShaderManager {
public:
	static EntityRenderDispatcher* entityRenderDispatcher;

	bool hasWaterHole							// 40
	mce::MaterialPtr entity_alphatest2;			// 44
	mce::MaterialPtr entity_alphatest_glint;	// 56
	mce::TexturePtr terrain_atlas; 				// 68
	mce::TexturePtr glint_texture;				// 80
	mce::MaterialPtr name_tag;					// 92
	mce::MaterialPtr name_tag_depth_tested;		// 104
	mce::MaterialPtr name_tag_depth_tested2;	// 116

	EntityRenderer(TextureGroup&, bool);
	virtual ~EntityRenderer();
	virtual void render(Entity&, const Vec3&, float, float) = 0;
	virtual void postRender(Entity&, const Vec3&, float, float);
	virtual void renderDebug(Entity&, Options&);
	virtual void renderWaterHole(Entity&, const Vec3&, const Vec2&, float);
	void renderText(Entity&, const std::sting*, float, float);
	void renderText(const std::string&, const Vec3&, const Color&, mce::MaterialPtr*, mce::MaterialPtr*);
	static void _emitFlame(Entity &, float);
	static void _emitSmoke(Entity &, float);
	static bool isFancy();
	static Font* getFont();
	static void init(EntityRenderDispatcher*);
	bool hasWaterHole() const;
};
