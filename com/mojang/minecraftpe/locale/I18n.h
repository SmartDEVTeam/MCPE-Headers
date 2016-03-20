#pragma once

#include <string.h>
#include <vector>

class I18n {
public:
	static std::string get(const std::string&, const std::vector<std::string>&);
};