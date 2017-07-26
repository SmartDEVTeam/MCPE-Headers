#pragma once

#include "Vec3.h"

//Size : 28
struct AABB {

	AABB();
	AABB(const Vec3&, float);
	AABB(const Vec3&, const Vec3&);
	AABB(float, float, float, float, float, float);

	void set(float, float, float, float, float, float);
	AABB& move(float, float, float);
	AABB& move(const Vec3&);
	bool operator==(const AABB&) const;
};
