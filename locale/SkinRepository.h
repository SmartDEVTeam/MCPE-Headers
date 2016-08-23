#pragma once

#include <string>
#include <vector>
class SkinPack;

// TODO: still needs fixing

class SkinRepository {
public:
	char filler[32];
	std::vector<SkinPack *> skinPacks;
};
