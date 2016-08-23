#pragma once

#include <stdint.h>

class Vec3;

class Random {
public:
	Random();
	uint32_t genrand_int32();
	Vec3& nextGaussianVec3();
};