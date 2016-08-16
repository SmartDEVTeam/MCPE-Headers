#pragma once

#include <string>

#include "texture/TextureLocation.h"

namespace mce {
	class TextureGroup;
	
	class TexturePtr {
	public:
		char filler1[16];	// 0

		TexturePtr(TexturePtr&&);
		TexturePtr(mce::TextureGroup&, const std::string&, TextureLocation);
		TexturePtr();
	};
};