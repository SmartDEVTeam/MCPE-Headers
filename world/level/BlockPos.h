#pragma once

class ChunkPos;
class Vec3;

class BlockPos
{
	int x, y, z;

	BlockPos(const ChunkPos &pos, int y);
	BlockPos(const Vec3 &pos);
	BlockPos(float x, float y, float z);
};
