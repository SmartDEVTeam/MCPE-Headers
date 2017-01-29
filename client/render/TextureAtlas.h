#pragma once

#include <string>
#include "../AppPlatformListener.h"

class TextureAtlasItem;
class ResourceLocation;
class ResourcePackManager;

namespace mce { class TextureGroup; };

class TextureAtlas : public AppPlatformListener
{
public:
	TextureAtlas(const ResourceLocation&, ResourcePackManager& mce::TextureGroup*);

	virtual ~TextureAtlas();
	virtual void onAppResumed();
	
	TextureAtlasItem& getTextureItem(const std::string&) const;
};

