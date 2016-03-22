#pragma once
#include "Vec3.h"

struct AABB {
	bool empty;
	Vec3 min;
	Vec3 max;

	AABB();
	AABB(const Vec3&, const Vec3&);
	AABB(float, float, float, float, float, float);

	void set(float, float, float, float, float, float);
	AABB& move(float, float, float);
};
