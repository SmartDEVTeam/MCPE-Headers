#pragma once
#include <stdint.h>

class Block;

typedef uint8_t DataID;
typedef uint8_t FacingID;

struct BlockID {
	unsigned char id;
	
	operator unsigned char() const {
		return id;
	}
	
	BlockID(BlockID const& other): id(other.id) {
	}
	
	BlockID(unsigned char id_): id(id_) {
	}
	
	const BlockID operator=(const BlockID rvalue) {
		id = rvalue.id;
		return *this;
	}
};

struct FullBlock {
	BlockID blockId;
	DataID data;

	FullBlock(BlockID id, DataID aux) : blockId(id), data(aux) {
	}
	
	FullBlock(unsigned char id, DataID aux) : blockId(BlockID(id)), data(aux) {
		
	}
	
	FullBlock(FullBlock const& other): blockId(other.blockId), data(other.data) {
	}
	
	Block* getBlock() const;
};