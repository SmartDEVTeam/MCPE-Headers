#pragma once

#include <memory>

class IntArrayTag;

class BoundingBox
{
public:
	int minX; // 0
	int minY; // 4
	int minZ; // 8
	int maxX; // 12
	int maxY; // 16
	int maxZ; // 20

	void orientBox(int, int, int, int, int, int, int, int, int, int);
	std::unique_ptr<IntArrayTag> createTag() const;
};
