#pragma once

#include <stdint.h>

struct BlockProperty;

struct BlockID {

    uint_fast8_t id;

    BlockID(uint_fast8_t id) : id(id) { }
    BlockID(const BlockID &b) : BlockID(b.id) { }

    bool operator==(const BlockID&b) { return id == b.id; }
    bool operator!=(const BlockID &b) { return !(*this == b); }

    bool hasProperty(BlockProperty) const;

    static BlockID AIR;
	
	operator unsigned char() const { return id; }

};

