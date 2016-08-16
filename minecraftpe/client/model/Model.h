#pragma once

#include <vector>

#include "../AppPlatformListener.h"
#include "../renderer/MaterialPtr.h"

class Entity;
class Mob;
class AABB;
class ModelPart;
class GeometryPtr;
namespace mce { class TexturePtr; };

// Size : 176
class Model : public AppPlatformListener {
public:
	char model_vars[12];					// 8
	mce::TexturePtr& texture;				// 20
	mce::MaterialPtr entity;				// 24
	mce::MaterialPtr entity_alphatest;		// 36
	mce::MaterialPtr entity_alphablend;		// 48
	mce::MaterialPtr entity_static;			// 60
	mce::MaterialPtr entity_emissive;		// 72
	mce::MaterialPtr entity_emissive_alpha;	// 84
	mce::MaterialPtr entity_change_color;	// 96
	mce::MaterialPtr entity_glint;			// 108
	mce::MaterialPtr entity_alphatest_glint;// 120
	mce::MaterialPtr charged_creeper 		// 132
	mce::MaterialPtr entity_alphatest_change_color;	// 144
	mce::MaterialPtr entity_alphatest_change_color_glint;	// 156
	std::vector<ModelPart*> modelParts;		// 168
	char model_vars2[8];					// 172

	Model();
	virtual ~Model();
	virtual void onAppSuspended();
	virtual void clear();
	virtual void render();
	virtual void render(Entity&, float, float, float, float, float, float);
	virtual void setupAnim(float, float, float, float, float, float);
	virtual void prepareMobModel(Mob&, float, float, float);
	AABB* buildAABB() const;
	void copyModelPart(const ModelPart&, ModelPart&);
	void registerParts(ModelPart&);
};
