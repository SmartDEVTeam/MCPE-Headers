#pragma once

#include <cmath>

struct BlockPos;

struct Vec3 {
	float x, y, z;

	static const Vec3 ZERO;
	static const Vec3 ONE;

	static const Vec3 UNIT_X, UNIT_Y, UNIT_Z;
	static const Vec3 NEG_UNIT_X, NEG_UNIT_Y, NEG_UNIT_Z;

	Vec3(float _x, float _y, float _z) : x(_x), y(_y), z(_z) {}
	Vec3(const BlockPos&);

	float lengthSquared() const;
	float length() const;

	void normalize();
	void setLength(float newLength);

	Vec3 operator+(Vec3 const& other) const;
	void operator+=(Vec3 const& other);
	Vec3 operator-(Vec3 const& other) const;
	void operator-=(Vec3 const& other);

	Vec3 operator*(float factor) const;
	void operator*=(float factor);
	Vec3 operator/(float factor) const;
	void operator/=(float factor);

	Vec3 operator-() const;
};