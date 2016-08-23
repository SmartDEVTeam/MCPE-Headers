#pragma once

#include <string>

// size: 8
// 0.15.6
struct ResourceLocation {
	std::string str1;
	std::string str2;

	std::string getFullPath() const;
};