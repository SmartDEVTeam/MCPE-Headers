#pragma once
class BlockPos;

struct Vec3 {
	float x, y, z;

	Vec3(float, float, float);
	Vec3(const BlockPos&);

	Vec3& extend(float, float, float);
	Vec3& extend(const Vec3&);
	Vec3& set(float, float, float);
	Vec3& normalize();
};
