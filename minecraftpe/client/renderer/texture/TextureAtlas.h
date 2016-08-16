#pragma once
#include <string>
#include "../../AppPlatformListener.h"
class TextureAtlasItem;
class ResourceLocation;

namespace mce { class TextureGroup; };

// 0.15.6
class TextureAtlas : public AppPlatformListener {
public:
	TextureAtlas(const ResourceLocation&, mce::TextureGroup*);
	
	TextureAtlasItem& getTextureItem(const std::string&) const;
};

