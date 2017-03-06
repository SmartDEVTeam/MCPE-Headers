#include <cstdint>
#include <math.h>

#include "Random.h"

Random::Random(long unsigned int seed)
{
	setSeed(seed);
}

void Random::setSeed(long unsigned int seed)
{
	_seed = seed;
	_mt[0] = seed;
	haveNextNextGaussian = false;
	nextNextGaussian = 0.0F;

	long unsigned int help = seed;
	long unsigned int multiplier = 0x6C078965;
	for(int i = 1; i < 624; ++i)
	{
		help ^= (help >> 30);
		help = (help * multiplier) + i;
		_mt[i] = help;
	}

	_mti = 624;
}

float Random::nextFloat()
{
	return ((float)nextInt(1000)) / ((float)1000);
}

int Random::nextInt(int max)
{
	return genrand_int32() % max;
}

bool Random::nextBool()
{
	return genrand_int32() % 2;
}

bool Random::nextBool(int max)
{
	return nextInt(max)==nextInt(max);
}

