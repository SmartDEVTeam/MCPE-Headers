#pragma once

#include <cstdint>
#include "block/BlockID.h"

class Block;

class FullBlock {

public:

    BlockID id;
    uint_fast8_t data;

    FullBlock() : id(0), data(0) {};
    FullBlock(BlockID id, uint_fast8_t data) : id(id), data(data) {};
    FullBlock(FullBlock const& b) : id(b.id), data(b.data) {};

    Block* getBlock() const;

    bool operator==(FullBlock const& b) { return id == b.id && data == b.data; }
    bool operator!=(FullBlock const& b) { return !(*this == b); }

    static FullBlock AIR;

};

