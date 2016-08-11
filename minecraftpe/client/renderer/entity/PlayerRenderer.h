#pragma once

#include <vector>

#include "HumanoidMobRenderer.h"

class PlayerModel;
class GeometryGroup;
class SkinInfoData;
class Player;

class PlayerRenderer : public HumanoidMobRenderer {
public:
	GeometryGroup& geometry; // 204

	PlayerRenderer(mce::TextureGroup&, GeometryGroup&, std::unique_ptr<PlayerModel>, float);
	virtual ~PlayerRenderer();
	virtual void render(Entity&, const Vec3&, float, float);
	virtual void prepareCarriedItem(Model&, Mob&, ItemInstance*);
	virtual void setupPosition(Entity&, const Vec3&, Matrix&);
	virtual void setupRotations(Entity&, float, float, Matrix&, float);
	virtual void additionalRendering(Model&, Mob&, float, float, float, float, float, float, float);
	virtual const mce::TexturePtr& getSkinPtr(Entity&) const;
	const mce::TexturePtr& _getSkinPtr(SkinInfoData&) const;
	void _updateAlphaTest(SkinInfoData&);
	Model& getModel(SkinInfoData&) const;
	void renderGui(SkinInfoData&, float, bool);
	void renderLeftHand(Player&, float);
	void renderRightHand(Player&, float);
};
