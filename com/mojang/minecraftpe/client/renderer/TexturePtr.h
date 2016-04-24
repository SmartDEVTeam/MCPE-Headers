#pragma once

#include <string>

class TextureGroup;

namespace mce {
	class TexturePtr {
	public:
		char filler1[12];	// 0

		TexturePtr(TexturePtr&&);
		TexturePtr(TextureGroup&, const std::string&);
		TexturePtr();
	};
};