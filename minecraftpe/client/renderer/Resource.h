#pragma once
#include <string>
class ResourceLocation;

class Resource {
public:
	static bool load(const ResourceLocation&, std::string&);
	static bool loadTexture(const ResourceLocation&);
};