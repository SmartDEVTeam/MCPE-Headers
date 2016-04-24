#pragma once

#include "HumanoidModel.h"

class PlayerModel : public HumanoidModel {
public:
	ModelPart rightSleeve; // 1312
	ModelPart leftSleeve; // 1472
	ModelPart leftPants; // 1632
	ModelPart rightPants; // 1792
	ModelPart jacket; // 1952
	ModelPart cloak; // 2112
	ModelPart helmet; // 2272
	ModelPart bodyArmor; // 2432
	ModelPart leftArmArmor; // 2592
	ModelPart rightArmArmor; // 2752

public:
	PlayerModel(const GeometryPtr&);
	virtual ~PlayerModel();
	virtual void render(Entity&, float, float, float, float, float, float);
	virtual void setupAnim(float, float, float, float, float, float);
	virtual void renderGui(Entity*, float, bool);
};
