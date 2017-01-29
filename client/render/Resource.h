#pragma once

#include <string>

class ResourceLocation;
class ResourceLoader;
class ResourceFileSystem;

class Resource
{
public:
	static bool load(const ResourceLocation&, std::string&);
	static bool loadTexture(const ResourceLocation&);
	static void registerLoader(ResourceFileSystem, std::unique_ptr<ResourceLoader, std::default_delete<ResourceLoader>>);
};

