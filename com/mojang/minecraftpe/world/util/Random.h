#pragma once

#include <stdint.h>

class Random {
public:
	Random();
	uint32_t genrand_int32();
};