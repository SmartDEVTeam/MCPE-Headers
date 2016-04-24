#pragma once

#include <vector>

#include "MobRenderer.h"

class HumanoidModel;

class HumanoidMobRenderer : public MobRenderer {
public:
	HumanoidModel& babyModel; // 180
	HumanoidModel& armorModel1; // 184
	HumanoidModel& armorModel2; // 188
	std::vector<mce::TexturePtr> armorTextures; // 192
	char hmr_vars[8]; // 196

	HumanoidMobRenderer(std::unique_ptr<HumanoidModel>, std::unique_ptr<HumanoidModel>, std::unique_ptr<HumanoidModel>, mce::TexturePtr, float);
	HumanoidMobRenderer(std::unique_ptr<HumanoidModel>, std::unique_ptr<HumanoidModel>, std::unique_ptr<HumanoidModel>, std::unique_ptr<HumanoidModel>, mce::TexturePtr, float);
	virtual ~HumanoidMobRenderer();
	virtual void render(Entity&, const Vec3&, float, float);
	virtual void prepareArmor(Mob&, ArmorSlot, float);
	virtual void prepareCarriedItem(Model&, Mob&, ItemInstance*);
	virtual void additionalRendering(Model&, Mob&, float, float, float, float, float, float, float);
	Model& getModel(Mob&) const;
	void initTextures();
	void renderInternal(HumanoidModel&, Entity&, const Vec3&, float, float);
};
