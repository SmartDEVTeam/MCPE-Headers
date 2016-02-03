#include "Vec3.h"
#include <cmath>

Vec3::Vec3(float _x, float _y, float _z) {
	x = _x, y = _y, z = _z;
}

Vec3& Vec3::extend(float _x, float _y, float _z) {
	x += _x, y += _y, z += _z;
	return *this;
}

Vec3& Vec3::extend(const Vec3& other) {
	x += other.x, y += other.y, z += other.z;
	return *this;
}

Vec3& Vec3::set(float _x, float _y, float _z) {
	x = _x, y = _y, z = _z;
	return *this;
}

Vec3& Vec3::normalize() {
	double root = std::sqrt(x * x + y * y + z * z);
	return root < 0.0001? set(0.0F, 0.0F, 0.0F) : set(x / root, y / root, z / root);
}
