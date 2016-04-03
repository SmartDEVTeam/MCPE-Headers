#pragma once

#include <string>
#include <vector>
class SkinPack;

class SkinRepository
{
public:
	char filler[32];
	 std::vector<SkinPack *> skinPacks;
};
