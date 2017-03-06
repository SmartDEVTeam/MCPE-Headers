#pragma once

class ChunkPos;

struct BlockPos
{
	int x, y, z;
	
	BlockPos(float, float, float);
	BlockPos(const Vec3&);
	BlockPos(const ChunkPos&, int);
	
	std::string toString() const;
	void center() const;
	void neighbor(signed char) const;
	void relative(signed char, int) const;
};

