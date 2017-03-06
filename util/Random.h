#pragma once

struct Random
{
public:
	Random() = default;
	Random(long unsigned int);

	void setSeed(long unsigned int);

	long unsigned int genrand_int32();

	float nextFloat();
	int nextInt(int);
	bool nextBool();
	bool nextBool(int);
protected:
	long unsigned int _seed;
	long unsigned int _mt[624];
	int _mti;
	bool haveNextNextGaussian;
	float nextNextGaussian;
};

