#pragma once

#include <string>
class Localization {
public:
	Localization(const std::string&);
	void _appendTranslations(const std::string&);
	void _load(const std::string&);
	std::string getFullLanguageCode() const;
};