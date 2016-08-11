#pragma once

#include "Model.h"
#include "ModelPart.h"

// Size : 1024
class QuadrupedModel : public Model
{
public:
	ModelPart head;		// 180
	ModelPart body;		// 340
	ModelPart leg1;		// 500
	ModelPart leg2;		// 660
	ModelPart leg3;		// 820
	ModelPart leg4;		// 980
	ModelPart leg5;		// 1140
	float idk_f;		// 1300
	float idk_f2;		// 1304

public:
	QuadrupedModel(const GeometryPtr&);
	QuadrupedModel(int, float, int, int);
	virtual ~QuadrupedModel();
	virtual void render(Entity&, float, float, float, float, float, float);
	virtual void setupAnim(float, float, float, float, float, float);
};
