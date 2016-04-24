#pragma once

#include "Model.h"
#include "ModelPart.h"

class HumanoidModel : public Model {
public:
	static float HAT_OVERLAY_SCALE;
	static float OVERLAY_SCALE;

	ModelPart head;		// 180
	ModelPart hat;	// 340
	ModelPart body;		// 500
	ModelPart rightArm;	// 660
	ModelPart leftArm;	// 820
	ModelPart rightLeg;	// 980
	ModelPart leftLeg;	// 1140
	bool isSneak;		// 1300
	bool hasBow;		// 1301
	float idk_f;		// 1304
	float idk_f1;		// 1308

	HumanoidModel(const GeometryPtr&);
	HumanoidModel(float, float, int, int);
	virtual ~HumanoidModel();
	virtual void render(Entity&, float, float, float, float, float, float);
	virtual void setupAnim(float, float, float, float, float, float);
	virtual void prepareMobModel(Mob&, float, float, float);
};
