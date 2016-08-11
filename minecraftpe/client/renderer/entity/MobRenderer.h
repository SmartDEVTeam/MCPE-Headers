#pragma once

#include <memory>

#include "EntityRenderer.h"

class Model;
class Mob;
class Matrix;
class ItemInstance;
class ArmorSlot;

// Size : 108
class MobRenderer : public EntityRenderer {
public:
	bool isRenderering;	// 128
	Model& mainModel; // 132
	mce::TexturePtr skin; // 136
	Model& armorModel; // 148
	char mr_vars[28]; // 152

	MobRenderer(std::unique_ptr<Model>, mce::TexturePtr, float);
	virtual ~MobRenderer();
	virtual void render(Entity&, const Vec3&, float, float);
	virtual void renderDebug(Entity&, Options&);
	virtual void prepareArmor(Mob&, ArmorSlot, float);
	virtual void prepareCarriedItem(Model&, Mob&, ItemInstance*);
	virtual void setupPosition(Entity&, const Vec3&, Matrix&);
	virtual void setupRotations(Entity&, float, float, Matrix&, float);
	virtual void getAttackAnim(Mob&, float);
	virtual void getBob(Mob&, float);
	virtual float getFlipDegrees(Mob&);
	virtual void scale(Mob&, Matrix&, float);
	virtual void additionalRendering(Model&, Mob&, float, float, float, float, float, float, float);
	virtual const mce::TexturePtr& getSkinPtr(Entity&) const;
	void renderModel(Model&, const mce::TexturePtr&, const Vec3&, float, float);
};
