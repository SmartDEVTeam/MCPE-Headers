#pragma once
#include "Vec3.h"

// size: 28
// 0.15.6
struct AABB {
	Vec3 min;
	Vec3 max;
	bool empty;

	AABB();
	AABB(const Vec3&, const Vec3&);
	AABB(float, float, float, float, float, float);

	void set(float, float, float, float, float, float);
	AABB& move(float, float, float);
	bool operator==(const AABB &) const;
};
