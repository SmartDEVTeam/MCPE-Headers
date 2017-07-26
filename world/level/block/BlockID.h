#pragma once

#include <stdint.h>

#include "BlockProperty.h"

struct BlockID
{
	uint_fast8_t id;

	BlockID(uint_fast8_t id) : id(id) { }
	BlockID(BlockID const& b) : BlockID(b.id) { }

	bool operator==(BlockID const& b) { return id == b.id; }
	bool operator!=(BlockID const& b) { return !(*this == b); }
	operator unsigned char() const { return id; }

	bool hasProperty(BlockProperty) const;

	static BlockID AIR;
};

