#pragma once
#include <stdint.h>

typedef uint_fast8_t DataID;
typedef int_fast8_t FacingID;

struct BlockID {
	unsigned char value;
	static const BlockID AIR;

	BlockID();
	BlockID(unsigned char);
	BlockID(const BlockID&);

	bool operator==(unsigned char);
	bool operator==(BlockID);
	BlockID& operator=(const unsigned char&);
	operator unsigned char();
	operator int();
};

struct FullBlock {
	static const FullBlock AIR;

	BlockID id;
	DataID data;

	FullBlock(BlockID, DataID);
	operator unsigned char();
};

struct Brightness {
	static uint_fast8_t MIN;
	static uint_fast8_t MAX;
};
