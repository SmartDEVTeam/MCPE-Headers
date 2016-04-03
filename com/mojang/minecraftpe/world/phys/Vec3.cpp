#include "Vec3.h"

//thanks @mackthehobbit! :)

float Vec3::lengthSquared() const {
	return x * x + y * y + z * z;
}

float Vec3::length() const {
	return sqrtf(lengthSquared());
}

void Vec3::normalize() {
	*this /= length();
}

void Vec3::setLength(float newLength) {
	*this /= (length() / newLength);
}

Vec3 Vec3::operator+(Vec3 const& other) const {
	return Vec3(x + other.x, y + other.y, z + other.z);
}

void Vec3::operator+=(Vec3 const& other) {
	x += other.x;
	y += other.y;
	z += other.z;
}

Vec3 Vec3::operator-(Vec3 const& other) const {
	return Vec3(x - other.x, y - other.y, z - other.z);
}

void Vec3::operator-=(Vec3 const& other) {
	x -= other.x;
	y -= other.y;
	z -= other.z;
}

Vec3 Vec3::operator*(float factor) const {
	return Vec3(x * factor, y * factor, z * factor);
}

void Vec3::operator*=(float factor) {
	x *= factor;
	y *= factor;
	z *= factor;
}

Vec3 Vec3::operator/(float factor) const {
	return Vec3(x / factor, y / factor, z / factor);
}

void Vec3::operator/=(float factor) {
	x /= factor;
	y /= factor;
	z /= factor;
}

Vec3 Vec3::operator-() const {
	return Vec3(-x, -y, -z);
}