#pragma once

#include <string>

namespace mce {
	
	class RenderMaterialGroup;
	
	class MaterialPtr {
	public:
		char filler1[12];	// 0

		MaterialPtr(MaterialPtr&&);
		MaterialPtr(mce::RenderMaterialGroup&, const std::string&);
		MaterialPtr();
	};
};