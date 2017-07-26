#pragma once

#include <memory>

#include "EntityRenderer.h"
#include "../../../world/item/ArmorSlot.h"

class ItemInstance;
class Matrix;
class Model;
class Mob;
namespace mce { class TexturePtr; };

class MobRenderer : public EntityRenderer
{
public:
	MobRenderer(EntityRenderDispatcher&, std::unique_ptr<Model, std::default_delete<Model>>, mce::TexturePtr, float);
	
	virtual ~MobRenderer();
	virtual void render(Entity&, const Vec3&, float, float);
	virtual void renderDebug(Entity&, Options&);
	virtual void renderLeash(Entity&, const Vec3&, float, float);
	virtual void prepareArmor(Mob&, ArmorSlot, float);
	virtual void prepareCarriedItem(Model&, Mob&, const ItemInstance&);
	virtual void setupPosition(const Entity&, const Vec3&, Matrix&) const;
	virtual void setupRotations(const Entity&, float, float, Matrix&, float) const;
	virtual void* getAttackAnim(Mob&, float);
	virtual void* getBob(Mob&, float);
	virtual void* getFlipDegrees(const Mob&) const;
	virtual void setupScale(const Mob&, Matrix&, float) const;
	virtual void additionalRendering(Model&, Mob&, float, float, float, float, float, float, float);
	virtual void renderLayers(Entity&, float, float, float, float, float);
	virtual void* getSkinPtr(Entity&) const;
};
