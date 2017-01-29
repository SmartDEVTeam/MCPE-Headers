#pragma once

#include <string>

struct ResourceLocation
{
	ResourceLocation();
	~ResourceLocation();
	
	std::string getFullPath() const;
};

