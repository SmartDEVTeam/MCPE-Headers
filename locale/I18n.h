#pragma once

#include <string>
#include <vector>

class Localization;

class I18n {
public:
	static std::string get(const std::string&, const std::vector<std::string>&);
	static std::string get(const std::string&);
	static Localization* getCurrentLanguage();
	static Localization* getLocaleFor(const std::string&);
	static void loadLanguages();
	static void chooseLanguage(const Localization&);
	static void chooseLanguage(const std::string&);
};