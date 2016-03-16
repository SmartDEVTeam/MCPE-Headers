#pragma once
#include <stdint.h>

typedef uint8_t DataID;
typedef uint8_t FacingID;

struct BlockID {
	uint8_t value;

	BlockID()
	{
		value = 0;
	}
	
	BlockID(int value)
	{
		this->value = value;
	}

	operator int()
	{
		return value;
	}

	const BlockID operator=(const BlockID rvalue)
	{
		value = rvalue.value;
		return *this;
	}
};

struct FullBlock {
	BlockID blockId;
	DataID data;

	FullBlock(int blockId, DataID data)
	{
		this->blockId = BlockID(blockId);
		this->data = data;
	}
};