#pragma once

class ChunkPos;
struct Vec3;

class BlockPos
{
public:
	int x, y, z;
	
	BlockPos(int x, int y, int z) : x(x), y(y), z(z) {}
	BlockPos(float, float, float);
	BlockPos(const Vec3&);
	BlockPos(const ChunkPos&, int);
	
	std::string toString() const;
	void center() const;
	void neighbor(signed char) const;
	void relative(signed char, int) const;
};

