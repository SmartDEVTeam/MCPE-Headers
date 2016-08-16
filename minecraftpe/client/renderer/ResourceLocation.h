#pragma once

#include <string>

// size: 8
// 0.15.6
class ResourceLocation {
public:
	std::string str1;
	std::string str2;

	ResourceLocation();
	ResourceLocation(const std::string&);
	std::string getFullPath() const;
};